#establish an id variable
id="LC81600432014154LGN00"

#use a for loop to reproject each of the bands you will be working with.
for BAND in {4,3,2}; do
 gdalwarp -t_srs EPSG:3857 $id"_B"$BAND.tif $BAND-projected.tif;done

#translate each of your bands into the 8-bit format with default settings of -ot and -scale
gdal_translate -ot Byte -scale 0 65535 0 255 4-projected{,-scaled}.tif
gdal_translate -ot Byte -scale 0 65535 0 255 3-projected{,-scaled}.tif
gdal_translate -ot Byte -scale 0 65535 0 255 2-projected{,-scaled}.tif

#merge the three reprojected band images into a single composite image
gdal_merge.py -v -ot Byte -separate -of GTiff -co PHOTOMETRIC=RGB -o $id-RGB-scaled.tif 4-projected-scaled.tif 3-projected-scaled.tif 2-projected-scaled.tif

#color correct blue bands to deal with haze and correct across all brands for brightness, contrast and saturation
convert -channel B -gamma 1.05 -channel RGB -sigmoidal-contrast 20,20% -modulate 100,150 $id-RGB-scaled.tif $id-RGB-scaled-cc.tif

#use a cubic downsampling method to add overview
gdaladdo -r cubic $id-RGB-scaled-cc.tif 2 4 8 10 12

#call the TIFF worldfile for the requested image
listgeo -tfw 3-projected.tif

#change name of file to match file needing georeference
mv 3-projected.tfw $id-RGB-scaled-cc.tfw

#georeference the image
gdal_edit.py -a_srs EPSG:3857 $id-RGB-scaled-cc.tif

#remove black background
gdalwarp -srcnodata 0 -dstalpha $id-RGB-scaled-cc.tif $id-RGB-scaled-cc-2.tif

import os, sys, PIL
from gdalconst import *
from osgeo import gdal

dset = gdal.Open(sys.argv[1])
'''
from PIL import Image
picture=Image.open(sys.argv[1])
'''
prefix = os.path.splitext(sys.argv[1])[0]

width = dset.RasterXSize
height = dset.RasterYSize

print width, 'x', height

tilesize = int(sys.argv[2])

for i in range(0,width,tilesize):
	for j in range(0,height, tilesize):
		w = min(1+tilesize,width)-i
		h = min(1+tilesize,height)-j
		gdaltranString = "gdal_translate -of JPEG -srcwin "+str(i)+", "+str(j)+", "+str(tilesize)+", "+str(tilesize)+" "+sys.argv[1]+" "+prefix+"_"+str(i)+"_"+str(j)+".jpg"
		os.system(gdaltranString)
		
removeextrafiles = "rm *.aux.xml"
os.system(removeextrafiles)

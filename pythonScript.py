# Hello World program in Python
    
import os,sys
os.system("mkdir test")
os.system("mkdir test2")
os.system("touch test2/status.txt")
os.system("touch test2/tile1.jpg")
os.system("touch test2/tile2.jpg")
os.system("touch test2/tile3.jpg")


os.system("echo ")
start_path = '.' # current directory
for path,dirs,files in os.walk(start_path):
    dirlen = len(dirs)
    if dirlen!=0:
        for file in os.walk(dirs[0]):
            dirfile = start_path+"/"+dirs[0]
            statusfile = start_path+"/"+str(dirs[0])+"/"+"status.txt"
            #print(dirs[0])
            if os.path.exists(statusfile):
                print("status file exists at "+statusfile)
                fp = open(statusfile,"r")
                os.system("ls -l "+dirfile+"/*tile*.jpg > "+dirfile+"/striplist.txt")
                #now read the tiles of the dir
                for dpath,ddir,tilefiles in os.walk(dirfile):
                    print(tilefiles[0])
                
                
                for i in tilefiles:
                    print(i)
                    
                    
            else:
                break
                
                
                    
                    
https://www.pythoncentral.io/recursive-file-and-directory-manipulation-in-python-part-1/
  
            
    
        The os.walk command is the way to loop through subfolders (and files) from a top level directory.  Example #1 is how to deal with folders, and example #2 is how to deal with the files within the folders.

Example #1: This code will attempt to compress any FGDB (a .gdb folder) under the rootDir
import os, fnmatch, arcgisscripting  
gp = arcgisscripting.create(9.3)  
rootDir = r"C:\temp"  
gdbList = []  
for dirPath, dirNames, fileNames in os.walk(rootDir, topdown=False):  
    if fnmatch.fnmatch(dirPath, "*.gdb") == True:  
        gdbList.append(dirPath)  
gdbCount = len(gdbList)  
if gdbCount == 0:  
    print "No matching FGDBs found!"  
else:  
    print "Attempting to compress " + str(gdbCount) + " geodatabases..."  
    for gdb in gdbList:  
        try:  
            gp.CompressFileGeodatabaseData_management(gdb)  
            print "Compressed " + gdb + "..."  
        except:  
            print "ERROR: Failed to compress " + gdb + "!"  


Example #2: This code will attempt to compress any PGDB (an .mdb file) under the rootDir
import os, fnmatch, arcgisscripting  
gp = arcgisscripting.create(9.3)  
rootDir = r"C:\temp"  
gdbList = []  
for dirPath, dirNames, fileNames in os.walk(rootDir, topdown=False):  
    for file in fileNames:  
        if fnmatch.fnmatch(file, "*.mdb") == True:  
            gdbList.append(dirPath + "\\" + file)  
gdbCount = len(gdbList)  
if gdbCount == 0:  
    print "No matching PGDBs found!"  
else:  
    print "Attempting to compact " + str(gdbCount) + " geodatabases..."  
    for gdb in gdbList:  
        try:  
            gp.Compact_management(gdb)  
            print "Compacted " + gdb + "..."  
        except:  
            print "ERROR: Failed to compact " + gdb + "!"   
    

    
#print (x)

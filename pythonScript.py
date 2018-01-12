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
                
                
                    
            
    
        
    

    
#print (x)

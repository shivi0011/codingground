#include <stdio.h>
#include<stdlib.h>

void readFile(FILE *fp)
{
    char ch;
        for(ch = fgetc(fp);ch!=EOF;ch = fgetc(fp))
        putchar(ch);
}

int main()
{
    FILE *fp;
    char filename[50],mode[4];
    int choice;
        
        do
        {
            printf("1.Read from File\n2.Write to File\n3.Exit\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("\n:::::::::::::: Available files are ::::::: \n");
                    system("ls -l");
                    printf("Enter file name : ");
                    scanf("%s",filename);
                    printf("Enter mode - r/w/a/r+/w+/a+");
                    scanf("%s",mode);
                    fp = fopen(filename,mode);      //need to take mode also as a string or array
                    if(fp==NULL)printf("Error in opening the file!");
                    readFile(fp);
                    fclose(fp);
                    break;
                    
                case 2:
                
                case 3:
                    exit(1);
                default:
                    printf("Please enter the correct choice!\n");
            }
            
            
        }while(1);
    return 0;
}


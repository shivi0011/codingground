#include <stdio.h>
#include<stdlib.h>

void writeInBinFile(FILE *fp,int num)
{
        char ch;
        //while(scanf("%d",&num)==1)
          //  fwrite(&num,sizeof(int),1,fp);
        int i,k=5;
        for(i=0;i<5;i++)
        {
            num = k++;
            fwrite(&num,sizeof(int),1,fp);
        }
        
}

void readBinFile(FILE *fp,int num)
{
        char ch;
        //while(fread(&num,sizeof(int),1,fp)==1)
          //  printf("%d ",num);
        
        int i;
        for(i=0;i<5;i++)
        {
            fread(&num,sizeof(int),1,fp);
            printf("%d ",num);
        }
}

int main()
{
    FILE *fp;
    int num,choice;
    
    
    do
    {
        printf("1.Write in Binary file\n2.Read from Binary file\n3.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                fp = fopen("num.dat","wb");
                if(fp==NULL)
                {
                    printf("Error in opening the file!");
                    return;
                }
                else
                {
                    writeInBinFile(fp,num);
                    fclose(fp);
                }    
            }
            case 2:
            {
                fp = fopen("num.dat","rb");
                if(fp==NULL)
                {
                    printf("Error in opening the file!");
                    return;
                }
                else
                {
                    readBinFile(fp,num);
                    while(fread(&num,sizeof(int),1,fp)==1)
                    {
                        printf("%d ",num);
                    }
                    /*rewind(fp);
                    if(feof(fp))
                    printf("End of file");
                    else
                    printf("Error in reading file!!\n");
                    fclose(fp);
                }   
            }
            case 3:
            exit(1);
            default:
            printf("Please enter correct choice!\n");
        }
        
    }while(1);
    return 0;
}


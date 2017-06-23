#include <stdio.h>

int main()
{
    FILE *fp1,*fp2;
    char fname[] = "test.txt";
    char tempfile[] = "temp.txt";
    fp1 = fopen(fname,"r");
    fp2 = fopen(tempfile,"w");
    if(fp1==NULL){printf("Error in opening the file!\n");return 0;}
    if(fp2==NULL){printf("Error in opening the file!\n");return 0;}
    
    int lineno,linecount=0;
    char newline[100],buff[200];
    printf("Enter new line : ");
    scanf("%s",newline);
    printf("Enter line no. to replace : ");
    scanf("%d",&lineno);
    
    while(!feof(fp1))
    {
        fgets(buff,200,fp1);
        linecount++;
        
        if(!feof(fp1))
        {
            if(linecount!=lineno)
            fprintf(fp2,"%s",buff);    
            else
            {fprintf(fp2,"%s",newline);fprintf(fp2,"%s","\n");}
        }
    }
    fclose(fp2);
    fp2 = fopen("temp.txt","r");
    while(fgets(buff,200,fp2))
    {
        printf("%s",buff);
    }
    fclose(fp1);
    fclose(fp2);
    
    remove(fname);
    rename(tempfile,fname);
    return 0;
}


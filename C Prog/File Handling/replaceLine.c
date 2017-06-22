#include <stdio.h>

int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("test.txt","r");
    fp2 =  fopen("temp.txt","w");
    if(fp1==NULL)printf("Error in opening the file!\n");
    if(fp2==NULL)printf("Error in opening the file!\n");
    
    printf("Enter text for new line to be inserted in file : ");
    char newline[255],line[255];
    int count=0,lineno;
    
    fgets(newline,255,stdin);
    printf("Enter the line no. u want to replace : ");
    scanf("%d",&lineno);
    
    while(!feof(fp1))
    {
        fgets(line,255,fp1);
        
        if(!feof(fp1))
        {
            if(count!=lineno)
            {
                fprintf(fp2,"%s",line);
            }
            else if(count==lineno)
            {
                fprintf(fp2,"%s",newline);
            }
        }
        
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}


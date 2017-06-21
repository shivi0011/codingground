#include <stdio.h>
#include<string.h>

void findNum(FILE *fp,char n[50])
{
    char ch,j,temp[50];
    int i,found=0;
    printf("hii %c",n[0]);
    
        for(ch=fgetc(fp);ch!=EOF;ch=fgetc(fp))
        {
            i=0;
            if(ch==n[0])
            {
                for(j=ch;j!=' '|| j!='\n'; j=fgetc(fp))
                {
                    temp[i++] = j;
                }    
                temp[i] = '\0';
                found=1;
            }
            if(found && !strcmp(temp,n))
            {printf("%s is found in file!!\n",n);return;}
        }
        printf("%s is not found in file!!\n",n);
}

int main()
{
    FILE *fp;
    char n[50];
    fp = fopen("test.txt","r");
    if(fp==NULL)printf("Error in opening the file!!\n");
    else
    {
        printf("Enter any number to search in the file : ");
        scanf("%s",n);
        findNum(fp,n);
    }

    return 0;
}


//https://stackoverflow.com/questions/1531268/getting-rgb-values-for-each-pixel-from-a-24bpp-bitmap-for-conversion-to-gba-form

#include <stdio.h>

int main()
{
    
    FILE *fp,*fp1;
    fp = fopen("lena_gray.raw","rb");
    if(fp==NULL)
    {printf("Error in opening the file!");return 0;}
    //else
    //{
        fp1 = fopen("out.raw","wb");
        if(fp1==NULL)
        {printf("Error in opening the file!");return 0;}
        
        //int i=0;
        unsigned char ch;
        while(1)
        {
            ch=fgetc(fp);
            //i++;
            
            if(!feof(fp))
            {
                //if(i>170)
                //{
                    if(ch==0)
                    {fputc(0x1ff-ch,fp1);}
                    else
                     fputc(0x1ff-ch,fp1);
                //}
                //else
                //fputc(ch,fp1);
            }
            else
            break;
        }
        
    //}
    
    fseek(fp,0,SEEK_SET);
    fseek(fp1,0,SEEK_SET);
    
    unsigned char chh,ch1;
    while(!feof(fp) && !feof(fp1))
    {
        chh = fgetc(fp);
        ch1 = fgetc(fp1);
        printf("%u ",chh+ch1);
        
    }
    
        fclose(fp);
        fclose(fp1);
        
        
        
    return 0;
}


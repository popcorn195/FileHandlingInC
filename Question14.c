//WAC to write and read content of a file and count number of words in it.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char ch;
    int n;
    int c=0;

    fp=fopen("sample.txt","w");
    if(fp==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    
    printf("Enter content of the file:\n");
    while((ch=getchar())!=EOF)
    {
        fputc(ch,fp);
    }
    fclose(fp);
    
    fp=fopen("sample.txt","r");
    if(fp==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    printf("\n\nContent of the file:\n");
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    //0 is 0 character away from current position 
    //2 is end position of the file
    fclose(fp);
    int pch='\n';
    fp=fopen("sample.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch==' '||ch=='\n')
        {
            c++;
        }
        pch=ch;
    }
    if(pch!='\n')
    {
        c++;
    }
    fclose(fp);
    printf("\n%d",c);
    return 0;
}

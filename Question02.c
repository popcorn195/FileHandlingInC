//WAC to write content into a file. Copy the contents of the file to another file and display content of copied file

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp, *fp1;
    char ch;

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
    fp1=fopen("copy.txt","w");
    if(fp==NULL||fp1==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(ch,fp1);
    }
    fclose(fp);
    fclose(fp1);
    
    fp1=fopen("copy.txt","r");
    if(fp1==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    
    printf("\n\nContent of the file:\n");
    while((ch=fgetc(fp1))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp1);
    
    return 0;
}

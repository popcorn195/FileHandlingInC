//WAC to write and read content of a file and count number of characters in it.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char ch;
    int n;

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
    fseek(fp,0,2);
    n=ftell(fp);
    printf("\nNumber of character in the file: %d\n",n);
    fclose(fp);
    
    return 0;
}

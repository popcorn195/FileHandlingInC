//WAC to count number of lines in a file.

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
    printf("\n\nContent of the file:\n");
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);

    fp=fopen("sample.txt","r");
    int c=0;
    int ch, pch='\n'; // Initialize previous character to newline to handle empty files
    // Count the number of newline characters
    while((ch=fgetc(fp))!=EOF) 
    {
        if (ch=='\n'&&pch!='\n') 
        {
            c++;
        }
        pch=ch;
    }
    // If the last line doesn't end with a newline
    if(pch!='\n') 
    {
        c++;
    }
    fclose(fp);
    printf("\n\nNumber of lines in the file: %d\n",c);
    
    return 0;
}

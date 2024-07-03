//Read 1st word of the file using fscanf() and display the current position from the 
//end of the file and number of bytes printed.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char ch;
    int n,n1,i;

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
    
    printf("\n\nContent of the file:\n");
    fp=fopen("sample.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    
    fp=fopen("sample.txt","r");
    char str1[20];
    // 99 to prevent buffer overflow
    //%99s tells fscanf() to read a string of characters from the input stream,         
    //up to a maximum of 99 characters, stopping at whitespace.
    if(fscanf(fp, "%99s", str1) == 1)//if first word was successfully read from the file 
    { 
        printf("\n\nFirst word in the file is: %s\n", str1);
        fseek(fp, 0, 1);
        n=ftell(fp);
        fseek(fp,0,2);
        n1=ftell(fp);
        printf("Current position from end of the file: %d\n",n1-n);
        printf("Number of bytes printed: %d\n",n);
    } 
    fclose(fp);
    
    return 0;
}

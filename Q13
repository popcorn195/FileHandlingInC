//WAC to compare content of file.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp, *fp1;
    char ch,ch1;
    int n,n1;

    fp=fopen("sample.txt","w");
    if(fp==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    printf("Enter content of the file 1:\n");
    while ((ch = getchar()) != '\n') 
    { // Read characters until newline
        fputc(ch, fp);
    }
    fclose(fp);
    fp1=fopen("sample1.txt","w");
    if(fp1==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    printf("\n\nEnter content of the file 2:\n");
    while((ch1 = getchar()) != '\n') 
    {
        fputc(ch1,fp1);
    }
    fclose(fp1);
    
    fp=fopen("sample.txt","r");
    fp1=fopen("sample1.txt","r");
    fseek(fp,0,2);
    n=ftell(fp);
    fseek(fp1,0,2);
    n1=ftell(fp1);
    if(n!=n1)
    {
       printf("\n\nfile content not equal\n");
       exit(1);
    }
    else
    {
        while((ch=fgetc(fp))!=EOF&&(ch1=fgetc(fp1))!=EOF)
        {
            if(ch!=ch1)
            {
                printf("\n\nfile content not equal\n");
                exit(1);
            }
        }
        printf("\n\nfile content is equal\n");
    }
    /*fp=fopen("sample.txt","r");
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
    */
    
    return 0;
}

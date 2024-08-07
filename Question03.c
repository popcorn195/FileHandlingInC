//WAC to write content into a file and store it to another file in reverse order

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp, *fp1;
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
    
    printf("\n\nContent of the file in reverse:\n");
    //-1 is 1 character away from current position(moving backwards) 
    //2 is end position of the file
    fseek(fp,-1,2);
    do{   
        n=ftell(fp);
        ch=fgetc(fp);
        printf("%c",ch);
        //-1 is 2 character away from the current position
        //1 is the current position og the cursor
        fseek(fp,-2,1);
    }while(n!=0);
    fclose(fp);
    
    return 0;
}

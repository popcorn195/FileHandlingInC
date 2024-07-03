//Count vowels,consonants,digits,special characters.

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
    int cv,cc,cd,cs;
    cv=cc=cd=cs=0;
    while((ch = fgetc(fp)) != EOF)
        /*or use
            while (fscanf(fp, "%s", &ch) != EOF)
        */
    {
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
            cv++;
        }
        else if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
        {
            cc++;
        }
        else if(ch>='0'&&ch<='9')
        {
            cd++;
        }
        else
        {
            cs++;
        }
    }
    printf("\n\nCount of:\n\tVowels: %d\n\tConsonants: %d\n\tDigits: %d\n\tSpecial Characters: %d\n\t",cv,cc,cd,cs);
    return 0;
}

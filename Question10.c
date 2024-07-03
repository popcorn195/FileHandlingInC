//WAC to append text in a existing file

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char text[1000];

    // Open the file in append mode
    fp = fopen("existing_file.txt", "a");

    if (fp == NULL) 
    {
        printf("File could not be opened.");
        exit(1);
    }

    printf("Enter text to append: ");
    fgets(text, sizeof(text), stdin);

    // Append text to the file
    fprintf(fp, "%s", text);

    // Close the file
    fclose(fp);

    printf("Text appended successfully.\n");

    return 0;
}

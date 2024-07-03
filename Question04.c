//WAC to input n integers in the file, separate odd and even integers in separate file and display the content of even file

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp, *fpeven, *fpodd;
    int num, n, i, co = 0, ce = 0;
    
    printf("Enter the limit: ");
    scanf("%d", &n);
    
    // Open the sample file in write mode
    fp = fopen("sample.txt", "w");
    if (fp == NULL) 
    {
        printf("File Error.\n");
        exit(1);
    }
    
    printf("\nEnter content of the file:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);
    
    // Reopen the sample file in read mode
    fp = fopen("sample.txt", "r");
    fpeven = fopen("even.txt", "w");
    fpodd = fopen("odd.txt", "w");
    if (fp == NULL || fpeven == NULL || fpodd == NULL) 
    {
        printf("File Error.\n");
        exit(1);
    }
    
    // Read integers from the sample file and sort them into odd and even files
    while (fscanf(fp, "%d", &num) != EOF)
    {
        if (num % 2 == 0)
        {
            fprintf(fpeven, "%d\n", num);
            ce++;
        }
        else
        {
            fprintf(fpodd, "%d\n", num);
            co++;
        }
    }
    fclose(fp);
    fclose(fpodd);
    fclose(fpeven);
    
    // Open the even file in read mode and display its content
    fpeven = fopen("even.txt", "r");
    if (fpeven == NULL) 
    {
        printf("File Error.\n");
        exit(1);
    }
    printf("Contents of even.txt:\n");
    while (fscanf(fpeven, "%d", &num) != EOF)
    {
       printf("%d ", num);
    }
    printf("\n");
    fclose(fpeven);
    
    return 0;
}




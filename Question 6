//WAC to create a database for library with fields book publisher, name, cost. 
//Input records of 'n' books and print the count of the books published by Oxford

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct books
{
   char pub[100];
   char name [50];
   float cost;
}bk;

int main ( )
{
    bk B[50];
    int i,n,r,c=0;
    FILE *fp;
    printf("Enter the number of books: ");
    scanf("%d",&n);
    
    fp = fopen ("student1.txt", "w");
    if(fp==NULL)
    {
        printf("\nFile does not exist\n");  
        exit(1);  
    }
   
    printf ("Enter details of Books:");
    for (i=0; i<n; i++)
    {
        printf ("\nBook %d", i+1);
        printf("\nBook Publisher: ");
        scanf("%s",B[i].pub);
        printf("Book name: ");
        scanf("%s",B[i].name);
        printf("Book cost: ");
        scanf("%f",&B[i].cost);
        fprintf(fp, "Book: %d\nPublisher: %s\nName: %s\nCost: %.2f\n\n",i+1,B[i].pub,B[i].name,B[i].cost);  
    }
    fclose (fp);

    fp = fopen ("student1.txt", "r");
    printf("\nThe content of file is:\n");
    char content[100];
    while (fgets(content, 100, fp)!=NULL) 
    {
        printf("%s",content);
    }
    fclose(fp);
    
    fp = fopen ("student1.txt", "r");
    i=0;
    while (fscanf(fp,"%s",content)!= EOF) 
    {
        r=strcasecmp(B[i].pub,"Oxford");
        if(r==0)
        {
            c++;
        }
        i++;
    }
        /* or use
            for(i=0;i<n;i++)
            {
                r=strcasecmp(B[i].name,"Oxford");
                if(r==0)
                {
                    c++;
                }
            }
        */
    printf("Count of the books published by Oxford is: %d\n",c);

    return 0;
}

//Read the file line by line and display line numbers along with lines

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    int lineNumber = 1;

    // Get the filename from the user
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file line by line and display line numbers along with lines
    printf("Contents of the file:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }

    // Close the file
    fclose(file);

    return 0;
}

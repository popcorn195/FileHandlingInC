//Separate vowvels and consonants in different file.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void separateVowelsAndConsonants(FILE *inputFile, FILE *vowelFile, FILE *consonantFile) {
    char ch,cont[1000];
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch); // Convert to lowercase for easier comparison
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                fputc(ch, vowelFile);
            } else {
                fputc(ch, consonantFile);
            }
        }
    }
    
}

int main() {
    FILE *inputFile, *vowelFile, *consonantFile;
    char text[1000];

    // Open the input file for writing
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Prompt user to enter text
    printf("Enter text:\n");
    fgets(text, sizeof(text), stdin);

    // Write text to input file
    fprintf(inputFile,"%s",text);
    fclose(inputFile);

    // Open the input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open files for vowels and consonants
    vowelFile = fopen("vowels.txt", "w");
    if (vowelFile == NULL) {
        printf("Error opening vowel file.\n");
        return 1;
    }

    consonantFile = fopen("consonants.txt", "w");
    if (consonantFile == NULL) {
        printf("Error opening consonant file.\n");
        return 1;
    }

    // Separate vowels and consonants into different files
    separateVowelsAndConsonants(inputFile, vowelFile, consonantFile);

    // Close all files
    fclose(inputFile);
    fclose(vowelFile);
    fclose(consonantFile);

    printf("Separation successful. Check the 'vowels.txt' and 'consonants.txt' files.\n");
    consonantFile = fopen("consonants.txt", "r");
    char cont[100];
    while(fscanf(consonantFile,"%s",cont)!=EOF)
    {
        printf("%s",cont);
    }
    fclose(consonantFile);
    return 0;
}

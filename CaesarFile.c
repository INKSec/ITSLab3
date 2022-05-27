#include <stdio.h>

void encrypt(char*, int);
void decrypt(char*, int);
int main() {

    int key;
    char filename[20];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", &filename);
    printf("Enter Key: ");
    scanf("%d", &key);
    fflush(stdin);
    encrypt(&filename, key);

    char decision;
    printf("Do you want to decrypt the file? (y/n): ");
    scanf("%c", &decision);
    if(decision == 'y') {
        printf("Enter the name of the file you want to encrypt: ");
        scanf("%s", &filename);
        printf("Enter Key: ");
        scanf("%d", &key);

        decrypt(&filename, key);
    } else {
        printf("Thank you for using Caesar Cipher!");
        exit(1);
    }
        
    
    
    


    return 0;
}

void encrypt(char* filename, int key) {
    FILE *inputFile, *outputFile;
    char ch;
    
    inputFile = fopen(filename, "r");
    
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    outputFile = fopen("outputEncrypt.txt", "w");
    if(outputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    do {
        ch = fgetc(inputFile);
        fputc(ch+key, outputFile);
    } while (ch != EOF); 

    printf("File encrypted!\n");
    printf("Check output.txt\n");
    fclose(inputFile);
    fclose(outputFile);
    

};

void decrypt(char* filename, int key) {
     FILE *inputFile, *outputFile;
    char ch;
    inputFile = fopen(filename, "r");
    if(inputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    outputFile = fopen("outputDecrypt.txt", "w");
    if(outputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    do {
        ch = fgetc(inputFile);
        fputc(ch-key, outputFile);
    } while (ch != EOF); 

    printf("File encrypted!\n");
    printf("Check output.txt\n");
    fclose(inputFile);
    fclose(outputFile);
};






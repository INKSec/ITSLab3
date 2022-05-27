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

    // matrix for encryption
    char** matrix = (char**)malloc(key * sizeof(char*));
    for(int i = 0; i < key; i++) {
        matrix[i] = (char*)malloc(10000 * sizeof(char));
    }

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

      
        

            for(int i = 0; i < key; i++) {
                for(int j = 0; j < key; j++) {
                    if(matrix[i][j] == EOF) {
                        break;
                    }
                    ch = fgetc(inputFile);
                    matrix[i][j] = ch;
                    //fputc(matrix[i][j], outputFile);
                }
            }
            for(int i = 0; i < key; i++) {
                for(int j = 0; j < key; j++) {
                    if(matrix[i][j] == EOF) {
                        break;
                    }
                    printf("%c", matrix[i][j]);
                }
            }
            // Die buchstaben in der Datei muessen gezaehlt werden und damit die laenge der MAtrix berechnet werden
            // So kann ich die Matrix auf die richtige Groesse anpassen



        
        
    

    
    
    fclose(inputFile);
    fclose(outputFile);
        
        
       
    

};


void decrypt(char* filename, int key) {

};

/*
while(1) {
    if(fgets (str, 100, inputFile) != NULL) {
      
            fputs(str, outputFile);
    } else {
        break;
    }
*/
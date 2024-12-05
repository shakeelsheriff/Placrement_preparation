/*  
    Name: Shakeel Sheriff M
    Batch: 24002
    Date: 05/12/2024
    Problem 7: Problem Statement: Caesar Cipher Challenge
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, int shift, char *ciphertext);
void decrypt(char *ciphertext, int shift, char *decryptedtext);
int isValidMessage(char *message);
int main(){
    char plaintext[100];
    char ciphertext[100];
    char decryptedtext[100];
    int shift;

    printf("Enter the plain test message : ");
    scanf("%100[^\n]",&plaintext);

    // Validate that the plaintext contains only alphabetic characters
    if (!isValidMessage(plaintext)) {
        printf("Invalid message. Only alphabetic characters are allowed.\n");
        return 1; // Exit with error code
    }

    printf("Enter the Shift value : ");
    scanf("%d", &shift);
    
    shift = shift % 26;

    // Encrypt the plaintext
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

int isValidMessage(char *plaintext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (!(isalpha(plaintext[i]) || plaintext[i] == ' ')){
            return 0; // False if non-alphabetic character found except space
        }
    }
    return 1; // True if all characters are alphabetic
}

void encrypt(char *plaintext, int shift, char *ciphertext){
    int i;
    for (i = 0; plaintext[i] != '\0'; i++){
        if (plaintext[i] >= 'A' &&  plaintext[i] <= 'Z'){
            ciphertext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
        } else if (plaintext[i] >= 'a' &&  plaintext[i] <= 'z'){
            ciphertext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the ciphertext string
}

void decrypt(char *ciphertext, int shift, char *decryptedtext){
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++){
        if (ciphertext[i] >= 'A' &&  ciphertext[i] <= 'Z'){
            decryptedtext[i] = (ciphertext[i] - 'A' - shift + 26) % 26 + 'A';
        } else if (ciphertext[i] >= 'a' &&  ciphertext[i] <= 'z'){
            decryptedtext[i] = (ciphertext[i] - 'a' - shift + 26) % 26 + 'a';
        } else {
            decryptedtext[i] = ciphertext[i];
        }
    }
    decryptedtext[i] = '\0';  // Null-terminate the decryptedtext string
}
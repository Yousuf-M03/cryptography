#include <stdio.h>
#include <string.h>
#include "caesar.h"
#include "vigenere.h"

int main(int argc, char *argv[]) {
    // Check if we have enough arguments
    if (argc < 4) {
        printf("\nUsage:\n");
        printf("  %s MODE ALGORITHM TEXT [KEY]\n\n", argv[0]);
        printf("Modes:\n");
        printf("  e, encrypt        Encrypt the input text\n");
        printf("  d, decrypt        Decrypt the input text\n\n");
        printf("Algorithms:\n");
        printf("  c, caesar         Caesar cipher\n");
        printf("  v, vigenere       Vigenère cipher\n\n");
        printf("Examples:\n");
        printf("  %s e c HELLO\n", argv[0]);
        printf("  %s decrypt v LQVRRBOFTQJ UGLE\n\n", argv[0]);
        return 1;
    }
    
    // Get command line arguments
    char *mode = argv[1];
    char *algorithm = argv[2];
    char *text = argv[3];
    
    // Check if mode is encrypt
    if (strcmp(mode, "e") == 0 || strcmp(mode, "encrypt") == 0) {
        // Encrypt mode
        
        // Check if algorithm is caesar
        if (strcmp(algorithm, "c") == 0 || strcmp(algorithm, "caesar") == 0) {
            // Caesar encryption
            caesar_encrypt(text);
            printf("%s\n", text);
        }
        // Check if algorithm is vigenere
        else if (strcmp(algorithm, "v") == 0 || strcmp(algorithm, "vigenere") == 0) {
            // Vigenere encryption - needs a key
            if (argc < 5) {
                printf("Error: Vigenère cipher needs a KEY\n");
                return 1;
            }
            char *key = argv[4];
            vigenere_encrypt(text, key);
            printf("%s\n", text);
        }
        else {
            printf("Error: Unknown algorithm '%s'\n", algorithm);
            return 1;
        }
    }
    // Check if mode is decrypt
    else if (strcmp(mode, "d") == 0 || strcmp(mode, "decrypt") == 0) {
        // Decrypt mode
        
        // Check if algorithm is caesar
        if (strcmp(algorithm, "c") == 0 || strcmp(algorithm, "caesar") == 0) {
            // Caesar decryption
            caesar_decrypt(text);
            printf("%s\n", text);
        }
        // Check if algorithm is vigenere
        else if (strcmp(algorithm, "v") == 0 || strcmp(algorithm, "vigenere") == 0) {
            // Vigenere decryption - needs a key
            if (argc < 5) {
                printf("Error: Vigenère cipher needs a KEY\n");
                return 1;
            }
            char *key = argv[4];
            vigenere_decrypt(text, key);
            printf("%s\n", text);
        }
        else {
            printf("Error: Unknown algorithm '%s'\n", algorithm);
            return 1;
        }
    }
    else {
        printf("Error: Unknown mode '%s'\n", mode);
        return 1;
    }
    
    return 0;
}

#include "vigenere.h"

char *vigenere_encrypt(char *plaintext, char *key) {
    int i = 0;
    int key_index = 0;
    
    // Find length of key
    int key_length = 0;
    while (key[key_length] != '\0') {
        key_length++;
    }
    
    // Loop through each character in plaintext
    while (plaintext[i] != '\0') {
        // Check if character is uppercase letter
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            // Get the shift amount from the key
            // Key letter A = shift 0, B = shift 1, etc.
            int shift = key[key_index % key_length] - 'A';
            
            // Encrypt this character with the shift
            int position = plaintext[i] - 'A';  // Get position 0-25
            position = (position + shift) % 26;  // Add shift and wrap around
            plaintext[i] = 'A' + position;  // Convert back to letter
            
            // Move to next key letter (but only for actual letters)
            key_index++;
        }
        // Non-letters are left unchanged and don't advance key
        i++;
    }
    
    return plaintext;
}

char *vigenere_decrypt(char *ciphertext, char *key) {
    int i = 0;
    int key_index = 0;
    
    // Find length of key
    int key_length = 0;
    while (key[key_length] != '\0') {
        key_length++;
    }
    
    // Loop through each character in ciphertext
    while (ciphertext[i] != '\0') {
        // Check if character is uppercase letter
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            // Get the shift amount from the key
            // Key letter A = shift 0, B = shift 1, etc.
            int shift = key[key_index % key_length] - 'A';
            
            // Decrypt this character by subtracting the shift
            // Add 26 before modulo to handle negative numbers
            int position = ciphertext[i] - 'A';  // Get position 0-25
            position = (position - shift + 26) % 26;  // Subtract shift and wrap around
            ciphertext[i] = 'A' + position;  // Convert back to letter
            
            // Move to next key letter (but only for actual letters)
            key_index++;
        }
        // Non-letters are left unchanged and don't advance key
        i++;
    }
    
    return ciphertext;
}

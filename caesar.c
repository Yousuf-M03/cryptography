#include "caesar.h"

char *caesar_encrypt(char *plaintext) {
    int i = 0;
    
    // Loop through each character in the string
    while (plaintext[i] != '\0') {
        // Check if character is uppercase letter
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            // Shift the character by CAESAR_SHIFT (3)
            // Convert to 0-25, add shift, use modulo for wraparound, convert back to A-Z
            int position = plaintext[i] - 'A';  // Get position 0-25
            position = (position + CAESAR_SHIFT) % 26;  // Add shift and wrap around
            plaintext[i] = 'A' + position;  // Convert back to letter
        }
        // Non-letters are left unchanged
        i++;
    }
    
    return plaintext;
}

char *caesar_decrypt(char *ciphertext) {
    int i = 0;
    
    // Loop through each character in the string
    while (ciphertext[i] != '\0') {
        // Check if character is uppercase letter
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            // Shift the character backwards by CAESAR_SHIFT (3)
            // We add 26 before modulo to handle negative numbers correctly
            int position = ciphertext[i] - 'A';  // Get position 0-25
            position = (position - CAESAR_SHIFT + 26) % 26;  // Subtract shift and wrap around
            ciphertext[i] = 'A' + position;  // Convert back to letter
        }
        // Non-letters are left unchanged
        i++;
    }
    
    return ciphertext;
}

#pragma once

/**
 * @file vigenere.h
 * @brief Vigenère cipher implementation for uppercase ASCII letters
 * 
 * This module implements the Vigenère cipher encryption and decryption
 * using a keyword to determine variable shifts for each character.
 */

/**
 * @brief Encrypt a string using Vigenère cipher in-place
 * 
 * Each letter in the plaintext is shifted by an amount determined by the
 * corresponding letter in the key (A=0, B=1, ..., Z=25). The key is repeated
 * as necessary to match the plaintext length.
 * 
 * @param plaintext The string to encrypt (modified in-place)
 * @param key The encryption key (uppercase letters only)
 * @return Pointer to the encrypted string (same as plaintext)
 * @note Only uppercase A-Z characters are encrypted
 */
char *vigenere_encrypt(char *plaintext, char *key);

/**
 * @brief Decrypt a string using Vigenère cipher in-place
 * 
 * Each letter in the ciphertext is shifted backward by an amount determined
 * by the corresponding letter in the key (A=0, B=1, ..., Z=25). The key is
 * repeated as necessary to match the ciphertext length.
 * 
 * @param ciphertext The string to decrypt (modified in-place)
 * @param key The decryption key (uppercase letters only)
 * @return Pointer to the decrypted string (same as ciphertext)
 * @note Only uppercase A-Z characters are decrypted
 */
char *vigenere_decrypt(char *ciphertext, char *key);

#pragma once

/**
 * @file caesar.h
 * @brief Caesar cipher implementation for uppercase ASCII letters
 * 
 * This module implements the Caesar cipher encryption and decryption
 * with a fixed shift of 3 positions in the alphabet.
 */

#ifndef CAESAR_SHIFT
#define CAESAR_SHIFT 3 /**< Default shift amount for Caesar cipher */
#endif

/**
 * @brief Encrypt a string using Caesar cipher in-place
 * 
 * Shifts each uppercase letter by CAESAR_SHIFT positions forward in the
 * alphabet with wraparound. Non-alphabetic characters are unchanged.
 * 
 * @param plaintext The string to encrypt (modified in-place)
 * @return Pointer to the encrypted string (same as input)
 * @note Only uppercase A-Z characters are encrypted
 */
char *caesar_encrypt(char *plaintext);

/**
 * @brief Decrypt a string using Caesar cipher in-place
 * 
 * Shifts each uppercase letter by CAESAR_SHIFT positions backward in the
 * alphabet with wraparound. Non-alphabetic characters are unchanged.
 * 
 * @param ciphertext The string to decrypt (modified in-place)
 * @return Pointer to the decrypted string (same as input)
 * @note Only uppercase A-Z characters are decrypted
 */
char *caesar_decrypt(char *ciphertext);

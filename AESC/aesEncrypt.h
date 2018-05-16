//
//  aesEncrypt.h
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#ifndef aesEncrypt_h
#define aesEncrypt_h

#include <stdio.h>
#include "constants.h"

void aes_encrypt(unsigned char message[4][4], unsigned char key[4][4]);
void aes_decrypt(unsigned char message[4][4], unsigned char key[4][4]);

void aes_encrypt_192(unsigned char message[4][4], unsigned char key[4][6]);
void aes_decrypt_192(unsigned char message[4][4], unsigned char key[4][6]);

void aes_encrypt_256(unsigned char message[4][4], unsigned char key[4][8]);
void aes_decrypt_256(unsigned char message[4][4], unsigned char key[4][8]);

void printMatrix(unsigned char mat[4][4]);
void printMatrix_large(unsigned char mat[4][44]);

#endif /* aesEncrypt_h */

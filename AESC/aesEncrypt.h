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

void aes_encrypt(unsigned char message[4][4], unsigned char key[4][4]);

void aes_decrypt(unsigned char message[4][4], unsigned char key[4][4]);

void printMatrix(unsigned char mat[4][4]);
void printMatrix_large(unsigned char mat[4][44]);

int getNumberOfBytes();
int getKeySize();

#endif /* aesEncrypt_h */

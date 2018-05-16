//
//  aesEncrypt.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include "aesEncrypt.h"
#include "byteSub.h"
#include "rowShift.h"
#include "keyExpansion.h"
#include "roundKey.h"
#include "mixColumn.h"

#pragma mark - 128 bits
void aes_encrypt(unsigned char message[4][4], unsigned char key[4][4])
{
    unsigned char key_expanded[4][44];
    expandKey(key, key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey(key_expanded, roundKey, 0);
    addRoundKey(message, roundKey);
    for (int i = 0; i < numberOfRound()-1; i ++) {
        
        byteSub(message);
        shiftRow(message);
        mix_col(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey(key_expanded, roundKey_enc, (i+1));
        addRoundKey(message, roundKey_enc);
    }
    byteSub(message);
    shiftRow(message);
    getRoundKey(key_expanded, roundKey, numberOfRound());
    addRoundKey(message, roundKey);
}

void aes_decrypt(unsigned char message[4][4], unsigned char key[4][4])
{
    unsigned char key_expanded[4][44];
    expandKey(key, key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey(key_expanded, roundKey, numberOfRound());
    
    addRoundKey(message, roundKey);
    
    for (int i = numberOfRound()-1; i > 0; i--) {
        
        inv_shiftRow(message);
        inv_byteSub(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey(key_expanded, roundKey_enc, i);
        addRoundKey(message, roundKey_enc);
        inv_mix_col(message);
    }
    inv_shiftRow(message);
    inv_byteSub(message);
    getRoundKey(key_expanded, roundKey, 0);
    addRoundKey(message, roundKey);
}


#pragma mark - 192 bits
void aes_encrypt_192(unsigned char message[4][4], unsigned char key[4][6])
{
    unsigned char key_expanded[4][52];
    expandKey_192(key, key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey_192(key_expanded, roundKey, 0);
    addRoundKey(message, roundKey);
    for (int i = 0; i < numberOfRound()-1; i ++) {
        
        byteSub(message);
        shiftRow(message);
        mix_col(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey_192(key_expanded, roundKey_enc, (i+1));
        addRoundKey(message, roundKey_enc);
    }
    byteSub(message);
    shiftRow(message);
    getRoundKey_192(key_expanded, roundKey, numberOfRound());
    addRoundKey(message, roundKey);
}

void aes_decrypt_192(unsigned char message[4][4], unsigned char key[4][6])
{
    unsigned char key_expanded[4][52];
    expandKey_192(key, key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey_192(key_expanded, roundKey, numberOfRound());
    
    addRoundKey(message, roundKey);
    
    for (int i = numberOfRound()-1; i > 0; i--) {
        
        inv_shiftRow(message);
        inv_byteSub(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey_192(key_expanded, roundKey_enc, i);
        addRoundKey(message, roundKey_enc);
        inv_mix_col(message);
    }
    inv_shiftRow(message);
    inv_byteSub(message);
    getRoundKey_192(key_expanded, roundKey, 0);
    addRoundKey(message, roundKey);
}


#pragma mark - 256 bits
void aes_encrypt_256(unsigned char message[4][4], unsigned char key[4][8])
{
    unsigned char key_expanded[4][60];
    expandKey_256(key, key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey_256(key_expanded, roundKey, 0);
    addRoundKey(message, roundKey);
    for (int i = 0; i < numberOfRound()-1; i ++) {
        
        byteSub(message);
        shiftRow(message);
        mix_col(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey_256(key_expanded, roundKey_enc, (i+1));
        addRoundKey(message, roundKey_enc);
    }
    byteSub(message);
    shiftRow(message);
    getRoundKey_256(key_expanded, roundKey, numberOfRound());
    addRoundKey(message, roundKey);
}

void aes_decrypt_256(unsigned char message[4][4], unsigned char key[4][8])
{
    unsigned char key_expanded[4][60];
    expandKey_256(key, key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey_256(key_expanded, roundKey, numberOfRound());
    
    addRoundKey(message, roundKey);
    
    for (int i = numberOfRound()-1; i > 0; i--) {
        
        inv_shiftRow(message);
        inv_byteSub(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey_256(key_expanded, roundKey_enc, i);
        addRoundKey(message, roundKey_enc);
        inv_mix_col(message);
    }
    inv_shiftRow(message);
    inv_byteSub(message);
    getRoundKey_256(key_expanded, roundKey, 0);
    addRoundKey(message, roundKey);
}

void printMatrix(unsigned char mat[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%x\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void printMatrix_large(unsigned char mat[4][44])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 44; j++) {
            printf("%x\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

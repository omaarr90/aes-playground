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

void printMatrix(unsigned char mat[4][4]);
void printMatrix_large(unsigned char mat[4][44]);

void aes_encrypt(unsigned char message[4][4], unsigned char key[4][4])
{
    unsigned char key_expanded[4][44];
    expandKey(key, key_expanded);
    printMatrix_large(key_expanded);
    
    unsigned char roundKey[4][4];
    getRoundKey(key_expanded, roundKey, 0);
    printf("\n--------- printing first round key ------\n");
    printMatrix(roundKey);
    
    printf("\n--------- original message ------\n");
    printMatrix(message);
    addRoundKey(message, roundKey);
    printf("\n--------- original message after first [round key] ------\n");
    printMatrix(message);
    
    for (int i = 0; i < 9; i ++) {
        byteSub(message);
        printf("\n--------- original message after first [byte sub] iteration %d ------\n", i);
        printMatrix(message);
        shiftRow(message);
        printf("\n--------- original message after first [shiftRow] iteration %d ------\n", i);
        printMatrix(message);
        mix_col(message);
        printf("\n--------- original message after first [mix_col] iteration %d ------\n", i);
        printMatrix(message);
        unsigned char roundKey_enc[4][4];
        getRoundKey(key_expanded, roundKey_enc, (i+1));
        printf("\n--------- round key after first [getRoundKey] iteration %d ------\n", i);
        printMatrix(roundKey_enc);
        addRoundKey(message, roundKey_enc);
        printf("\n--------- original message after first [addRoundKey] iteration %d ------\n", i);
        printMatrix(message);
    }
    
    byteSub(message);
    printf("\n--------- original message after last [byte sub] iteration ------\n");
    printMatrix(message);
    shiftRow(message);
    printf("\n--------- original message after last [shiftRow] iteration ------\n");
    printMatrix(message);
    getRoundKey(key_expanded, roundKey, 10);
    printf("\n--------- roundKey after last [getRoundKey] iteration ------\n");
    printMatrix(roundKey);
    addRoundKey(message, roundKey);
    printf("\n--------- original message after last [addRoundKey] iteration ------\n");
    printMatrix(message);
    
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

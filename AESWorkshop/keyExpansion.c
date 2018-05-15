//
//  keyExpansion.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include "keyExpansion.h"
#include "byteSub.h"

const unsigned char rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

void moveColumns(unsigned char a[4][4], unsigned char b[4][44]);
void rotateUpSide(unsigned char col [4][1]);
void xorWithRcon(unsigned char col[4][1], int index);
void xorColumns(unsigned char a[4][1], unsigned char b[4][1], unsigned char tmp [4][1]);
void printMatrix_one(unsigned char mat[4][1]);

void expandKey(unsigned char key[4][4] , unsigned char expandedKey[4][44])
{
    moveColumns(key, expandedKey);
    
    for (int i = 4; i < 44; i++) {
        unsigned char colWPrevI[4][1];
        unsigned char colWPrevIFour[4][1];
        for (int j = 0; j < 4; j++) {
            colWPrevIFour[j][0] = expandedKey[j][i-4];
        }
        for (int j = 0; j < 4; j++) {
            colWPrevI[j][0] = expandedKey[j][i-1];
        }
        printMatrix_one(colWPrevI);
        printMatrix_one(colWPrevIFour);
        if (i%4  == 0) {
            //we have a multiple of 4
            rotateUpSide(colWPrevI);
            printMatrix_one(colWPrevI);
            byteSub_key(colWPrevI);
            printMatrix_one(colWPrevI);
            xorWithRcon(colWPrevI, (i/4) - 1);
            printMatrix_one(colWPrevI);
        }
        unsigned char temp [4][1];
        xorColumns(colWPrevI, colWPrevIFour, temp);
        for (int j = 0; j < 4; j++) {
            expandedKey[j][i] = temp[j][0];
        }
    }
    
}

void getRoundKey(unsigned char expanedKey[4][44], unsigned char roundKey[4][4], int round)
{
    for (int i = 0; i < 16; i ++) {
        roundKey[i%4][i/4] = expanedKey[i%4][(i/4) + (round * 4)];
    }
}

void moveColumns(unsigned char a[4][4], unsigned char b[4][44])
{
    for (int i = 0; i < 16; i++) {
        b[i%4][i/4] = a[i%4][i/4];
    }
}

void rotateUpSide(unsigned char col [4][1])
{
    unsigned char tmp = col[0][0];
    col[0][0] = col[1][0];
    col[1][0] = col[2][0];
    col[2][0] = col[3][0];
    col[3][0] = tmp;
}

void xorWithRcon(unsigned char col[4][1], int index)
{
    col[0][0] ^= rcon[index];
}

void xorColumns(unsigned char a[4][1], unsigned char b[4][1], unsigned char tmp [4][1])
{
    for (int i = 0; i < 4; i++) {
        tmp[i][0] = a[i][0] ^ b[i][0];
    }
}

void printMatrix_one(unsigned char mat[4][1])
{
    for (int i = 0; i < 4; i++) {
        printf("%x\t", mat[i][0]);
        printf("\n");
    }
    printf("\n");
}

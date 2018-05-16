//
//  mixColumn.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include "mixColumn.h"

void matrix_multiply( unsigned char b[4][1]);
unsigned char shiftLeft_mix(unsigned char x);
unsigned char mix_col_multiply(unsigned char a, unsigned char b);
void inv_matrix_multiply( unsigned char b[4][1]);
unsigned char inv_mix_col_multiply(unsigned char a, unsigned char b);


const  unsigned char MIX_COL[4][4] =
{
    0x02, 0x03, 0x01, 0x01,
    0x01, 0x02, 0x03, 0x01,
    0x01, 0x01, 0x02, 0x03,
    0x03, 0x01, 0x01, 0x02
};

const  unsigned char INV_MIX_COL[4][4] =
{
    0x0E, 0x0B, 0x0D, 0x09,
    0x09, 0x0E, 0x0B, 0x0D,
    0x0D, 0x09, 0x0E, 0x0B,
    0x0B, 0x0D, 0x09, 0x0E
};

#pragma mark - mix columns
void mix_col(unsigned char state[4][4])
{
    for (int i = 0; i < 4; i++) {
        unsigned char col[4][1];
        for (int j = 0; j < 4; j++) {
            col[j][0] = state[j][i];
        }
        matrix_multiply(col);
        for (int x = 0; x < 4; x++) {
            state[x][i] = col[x][0];
        }
    }
}

void matrix_multiply( unsigned char b[4][1])
{
    unsigned char result[4][1];
    for (int i = 0; i < 4; i++) {
        
        unsigned char tmp = 0x00;
        for (int j = 0; j < 4; j++) {
            tmp  ^= mix_col_multiply(MIX_COL[i][j], b[j][0]);
        }
        result[i][0] = tmp;
        tmp = 0x00;
    }
    for (int i = 0; i < 4; i++) {
        b[i][0] = result[i][0];
    }
}

unsigned char mix_col_multiply(unsigned char a, unsigned char b)
{
    if (a == 0x01) {
        return b;
    }
    if (a == 0x02) {
        unsigned char tmp = shiftLeft_mix(b);
        return tmp;
    }
    
    unsigned char tmp = b;
    tmp = shiftLeft_mix(tmp);
    
    tmp = (tmp ^ b);
    return tmp;
}

#pragma mark - inverse mix columns
void inv_mix_col(unsigned char state[4][4])
{
    for (int i = 0; i < 4; i++) {
        unsigned char col[4][1];
        for (int j = 0; j < 4; j++) {
            col[j][0] = state[j][i];
        }
        inv_matrix_multiply(col);
        for (int x = 0; x < 4; x++) {
            state[x][i] = col[x][0];
        }
    }
}

void inv_matrix_multiply( unsigned char b[4][1])
{
    unsigned char result[4][1];
    for (int i = 0; i < 4; i++) {
        
        unsigned char tmp = 0x00;
        for (int j = 0; j < 4; j++) {
            tmp  ^= inv_mix_col_multiply(INV_MIX_COL[i][j], b[j][0]);
        }
        result[i][0] = tmp;
        tmp = 0x00;
    }
    for (int i = 0; i < 4; i++) {
        b[i][0] = result[i][0];
    }
}
unsigned char inv_mix_col_multiply(unsigned char a, unsigned char b)
{
    unsigned char TMP_1 = shiftLeft_mix(b);
    unsigned char TMP_2 = shiftLeft_mix(TMP_1);
    unsigned char TMP_3 = shiftLeft_mix(TMP_2);
    
    if (a == 0x09) {
        return TMP_3 ^ b;
    }

    if (a == 0x0B) {
        return TMP_3 ^ TMP_1 ^ b;
    }
    
    if (a == 0x0D) {
        return TMP_3 ^ TMP_2 ^ b;
    }

    if (a == 0x0E) {
        return TMP_3 ^ TMP_2 ^ TMP_1;
    }
    
    return b;
}

#pragma mark - common
unsigned char shiftLeft_mix(unsigned char x)
{
    unsigned char result = x + x ^ (0x1b & -(x >> 7));
    return result;
}



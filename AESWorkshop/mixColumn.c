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

const  unsigned char MIX_COL[4][4] =
{
    0x02, 0x03, 0x01, 0x01,
    0x01, 0x02, 0x03, 0x01,
    0x01, 0x01, 0x02, 0x03,
    0x03, 0x01, 0x01, 0x02
};

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
    
    tmp = (tmp ^ b);// % 0x1b;
    return tmp;
}

unsigned char shiftLeft_mix(unsigned char x)
{
    unsigned char result = x + x ^ (0x1b & -(x >> 7));
    return result;
}


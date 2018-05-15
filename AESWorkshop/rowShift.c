//
//  rowShift.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include "rowShift.h"

void base_shiftLeft(unsigned int row, unsigned char state[4][4]);
void shiftLeft(unsigned int row,unsigned int count, unsigned char state[4][4]);

void shiftRow(unsigned char state[4][4])
{
    for (int i = 0; i < 4; i++) {
        shiftLeft(i, i, state);
    }
}

#pragma mark - supporting methods
void base_shiftLeft(unsigned int row, unsigned char state[4][4])
{
    unsigned char tmp = state[row][3];
    state[row][3] = state[row][0];
    state[row][0] = state[row][1];
    state[row][1] = state[row][2];
    state[row][2] = tmp;
    
}

void shiftLeft(unsigned int row,unsigned int count, unsigned char state[4][4])
{
    for (int i = 0; i < count; i++) {
        base_shiftLeft(row, state);
    }
}

#pragma mark - inverse

void inv_shiftRow(unsigned char state[4][4])
{
}

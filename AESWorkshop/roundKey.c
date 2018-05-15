//
//  roundKey.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include "roundKey.h"

void addRoundKey(unsigned char state[4][4], unsigned char roundKey[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] ^= roundKey[i][j];
        }
//        state[i%4][i/4] = state[i%4][i/4] ^ roundKey[i%4][i/4];
    }
}

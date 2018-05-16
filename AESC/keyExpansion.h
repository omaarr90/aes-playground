//
//  keyExpansion.h
//  AESWorkshop
//
//  Created by Omar Alshammari on 29/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#ifndef keyExpansion_h
#define keyExpansion_h

#include <stdio.h>

void expandKey(unsigned char key[4][4] , unsigned char expandedKey[4][44]);
void getRoundKey(unsigned char expanedKey[4][44], unsigned char roundKey[4][4], int  round);

void expandKey_192(unsigned char key[4][6] , unsigned char expandedKey[4][52]);
void getRoundKey_192(unsigned char expanedKey[4][52], unsigned char roundKey[4][4], int round);

void expandKey_256(unsigned char key[4][8] , unsigned char expandedKey[4][60]);
void getRoundKey_256(unsigned char expanedKey[4][60], unsigned char roundKey[4][4], int round);

#endif /* keyExpansion_h */

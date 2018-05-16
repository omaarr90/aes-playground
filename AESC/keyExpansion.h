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
#endif /* keyExpansion_h */

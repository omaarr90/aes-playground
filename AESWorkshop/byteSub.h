//
//  byteSub.h
//  AESWorkshop
//
//  Created by Omar Alshammari on 28/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#ifndef byteSub_h
#define byteSub_h

#include <stdio.h>

void byteSub(unsigned char state[4][4]);
void inv_byteSub(unsigned char state[4][4]);

void byteSub_key(unsigned char state[4][1]);
#endif /* byteSub_h */

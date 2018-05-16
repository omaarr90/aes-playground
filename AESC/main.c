//
//  main.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 28/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include <stdio.h>
#include "aesEncrypt.h"

void printMatrix(unsigned char mat[4][4]);





void startDemo(unsigned char key[], unsigned char state[4][4]){
    
    unsigned char key_state[4][4];

    for (int i = 0; i < getNumberOfBytes(); i++) {
        
        key_state[i%4][i/4] = key[i];
    }
    
    printf("\n--------- ENCRYOTING ------\n");
    printf("\n--------- original message ------\n");
    printMatrix(state);
    aes_encrypt(state, key_state);
    printf("\n--------- CIPHER TEXT ------\n");
    printMatrix(state);
    
    
    printf("\n--------- DECRYOTING ------\n");
    printf("\n--------- CIPHER TEXT ------\n");
    printMatrix(state);
    aes_decrypt(state, key_state);
    printf("\n--------- original message ------\n");
    printMatrix(state);
    
}

//32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    unsigned char message[16] = {
        0x32, 0x43, 0xf6, 0xa8,
        0x88, 0x5a, 0x30, 0x8d,
        0x31, 0x31, 0x98, 0xa2,
        0xe0, 0x37, 0x07, 0x34
    };
    
    unsigned char state[4][4];
    for (int i = 0; i < 16; i++) {
        state[i%4][i/4] = message[i];
    }
    
    
    if (getKeySize() == 128) {
        unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
        startDemo(key, state);
    }else if (getKeySize() == 192){
        unsigned char key[24] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c, 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6};
        startDemo(key, state);

    }else if (getKeySize() == 256){
        unsigned char key[32] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c, 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f};
        startDemo(key, state);

    }


    


    return 0;
}

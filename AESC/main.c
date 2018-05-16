//
//  main.c
//  AESWorkshop
//
//  Created by Omar Alshammari on 28/08/1439 AH.
//  Copyright © 1439 Omar Alshammari. All rights reserved.
//

#include <stdio.h>
#include "aesEncrypt.h"
#include "constants.h"

void printMatrix(unsigned char mat[4][4]);

void printAsString(unsigned char a[4][4], char message[])
{
    printf("%s", message);
    for (int i = 0; i < 16; i++) {
        printf("%x", a[i%4][i/4]);
    }
    
    printf("\n");
}


void startDemo(unsigned char key[], unsigned char state[4][4], unsigned int key_size){
    
    printAsString(state, "message is: ");

    unsigned char key_state[4][key_size];
    for (int i = 0; i < getNumberOfBytes(); i++) {
        
        key_state[i%4][i/4] = key[i];
    }
    
    printf("\n--------- original message ------\n");
    printMatrix(state);
    if (getKeySize() == 128) {
        aes_encrypt(state, key_state);
    }else if (getKeySize() == 192){
        aes_encrypt_192(state, key_state);
    }else if (getKeySize() == 256){
        aes_encrypt_256(state, key_state);
    }
    printf("\n--------- CIPHER TEXT ------\n");
    printMatrix(state);
    
    printAsString(state, "message after encryption is: ");

    printf("\n--------- DECRYOTING ------\n");
    printf("\n--------- CIPHER TEXT ------\n");
    printMatrix(state);
    if (getKeySize() == 128) {
        aes_decrypt(state, key_state);
    }else if (getKeySize() == 192){
        aes_decrypt_192(state, key_state);
    }else if (getKeySize() == 256){
        aes_decrypt_256(state, key_state);
    }
    
    printf("\n--------- original message ------\n");
    printMatrix(state);
    
}

//32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    unsigned char message[16] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
    };
    
    unsigned char state[4][4];
    for (int i = 0; i < 16; i++) {
        state[i%4][i/4] = message[i];
    }
    
    
    if (getKeySize() == 128) {
        unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
        startDemo(key, state, 4);
    }else if (getKeySize() == 192){
        unsigned char key[24] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
        startDemo(key, state, 6);

    }else if (getKeySize() == 256){
        unsigned char key[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e,0x1f};
        startDemo(key, state, 8);

    }


    


    return 0;
}

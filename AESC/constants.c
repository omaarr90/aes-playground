//
//  constants.c
//  AESC
//
//  Created by Omar Alshammari on 01/09/1439 AH.
//  Copyright © 1439 Nahar Alkhodair. All rights reserved.
//

#include "constants.h"


int getKeySize(){
    
    return 256;
};


int getNumberOfBytes(){
    
    return getKeySize()/8;
}

int numberOfRound(){
    
    if (getKeySize() == 128) {
        return 10;
    }else if (getKeySize() == 192){
        return 12;
    }else if (getKeySize() == 256){
        return 14;
    }
    
    return 0;
    
}

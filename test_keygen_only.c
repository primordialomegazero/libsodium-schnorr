#include <stdio.h>
#include "schnorr.h"

int main() {
    unsigned char pk[33], sk[32];
    printf("Testing keygen...\n"); fflush(stdout);
    
    int ret = schnorr_keypair(pk, sk);
    printf("Keygen result: %d\n", ret);
    printf("PK[0]: %02x, SK[0]: %02x\n", pk[0], sk[0]);
    
    return ret;
}

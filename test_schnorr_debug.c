#include <stdio.h>
#include <string.h>
#include "schnorr.h"

int main() {
    unsigned char pk[33], sk[32], sig[65];
    size_t siglen = 65;
    
    schnorr_keypair(pk, sk);
    printf("PK: %02x%02x%02x%02x\n", pk[0], pk[1], pk[2], pk[3]);
    printf("SK: %02x%02x%02x%02x\n", sk[0], sk[1], sk[2], sk[3]);
    
    unsigned char msg[] = "Schnorr Σ-Protocol";
    schnorr_sign(msg, 19, sk, sig, &siglen);
    printf("SIG: %02x%02x%02x%02x... (%zu bytes)\n", sig[0], sig[1], sig[2], sig[3], siglen);
    
    int r1 = schnorr_verify(sig, siglen, msg, 19, pk);
    printf("Verify 1 (original): %d\n", r1);
    
    // Try with strlen instead of hardcoded
    int r2 = schnorr_verify(sig, siglen, msg, strlen((char*)msg), pk);
    printf("Verify 2 (strlen): %d\n", r2);
    
    return 0;
}

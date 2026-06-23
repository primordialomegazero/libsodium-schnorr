#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "curves/ed25519.h"

int main() {
    unsigned char pk[32], sk[32], sig[64];
    size_t slen = 64;
    
    printf("=== ED25519 ISO TEST ===\n");
    
    printf("Keygen...\n"); fflush(stdout);
    int r1 = ed25519_keypair(pk, sk);
    printf("Keygen: %d\n", r1); fflush(stdout);
    
    printf("Sign...\n"); fflush(stdout);
    unsigned char msg[] = "ed25519";
    int r2 = ed25519_sign(sig, &slen, msg, 7, sk);
    printf("Sign: %d, slen: %zu\n", r2, slen); fflush(stdout);
    
    printf("Verify...\n"); fflush(stdout);
    int r3 = ed25519_verify(sig, slen, msg, 7, pk);
    printf("Verify: %d\n", r3); fflush(stdout);
    
    if (r3 == 0) printf("ED25519: PASS\n");
    else printf("ED25519: FAIL\n");
    
    return 0;
}

#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "curves/ed25519.h"

int main() {
    unsigned char pk[32], sk[32], sig[64];
    size_t slen = 64;
    unsigned char msg[] = "ed25519";
    
    printf("=== TRACE ===\n");
    
    // Keygen
    ed25519_keypair(pk, sk);
    printf("pk[0..3]: %02x%02x%02x%02x\n", pk[0], pk[1], pk[2], pk[3]);
    printf("sk[0..3]: %02x%02x%02x%02x\n", sk[0], sk[1], sk[2], sk[3]);
    
    // Sign
    ed25519_sign(sig, &slen, msg, 7, sk);
    printf("sig[0..7]: %02x%02x%02x%02x%02x%02x%02x%02x\n", 
           sig[0], sig[1], sig[2], sig[3], sig[4], sig[5], sig[6], sig[7]);
    printf("slen: %zu\n", slen);
    
    // Manual verify — reconstruct what schnorr_verify sees
    unsigned char secp_pk[33], secp_sig[65];
    secp_pk[0] = 0x02;
    memcpy(secp_pk + 1, pk, 32);
    memset(secp_sig, 0, 65);
    memcpy(secp_sig, sig, 64);
    
    printf("secp_pk[0..3]: %02x%02x%02x%02x\n", secp_pk[0], secp_pk[1], secp_pk[2], secp_pk[3]);
    printf("secp_sig[0..7]: %02x%02x%02x%02x%02x%02x%02x%02x\n",
           secp_sig[0], secp_sig[1], secp_sig[2], secp_sig[3], 
           secp_sig[4], secp_sig[5], secp_sig[6], secp_sig[7]);
    
    // Try direct schnorr_verify
    int r1 = schnorr_verify(secp_sig, 65, msg, 7, secp_pk);
    printf("Direct schnorr_verify: %d\n", r1);
    
    // Try with original key (before ed25519 conversion)
    unsigned char orig_pk[33], orig_sk[32], orig_sig[65];
    size_t orig_slen = 65;
    schnorr_keypair(orig_pk, orig_sk);
    schnorr_sign(msg, 7, orig_sk, orig_sig, &orig_slen);
    int r2 = schnorr_verify(orig_sig, orig_slen, msg, 7, orig_pk);
    printf("Native schnorr_verify: %d\n", r2);
    
    return 0;
}

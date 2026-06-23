#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "clown_ecosystem/dnscrypt/dnscrypt_proxy.h"
#include "clown_ecosystem/libhydrogen/hydrogen.h"
#include "clown_ecosystem/minisign/minisign.h"

int main() {
    unsigned char pk[33], sk[32];
    schnorr_keypair(pk, sk);
    
    printf("=== WRAPPER TESTS ===\n");
    
    // DNScrypt
    unsigned char query[] = "example.com";
    unsigned char sq[256];
    size_t sq_len = 256;
    int dns_sign = dnscrypt_sign_query(sq, &sq_len, query, 11, sk);
    printf("DNScrypt sign: %d\n", dns_sign);
    int dns_verify = dnscrypt_verify_response(query, 11, sq, pk);
    printf("DNScrypt verify: %d\n", dns_verify);
    
    // libhydrogen
    unsigned char h_sig[65]; size_t hs_len = 65;
    int hydro_sign = hydro_sign_create(h_sig, &hs_len, (unsigned char*)"Hydro", 5, sk);
    printf("Hydro sign: %d\n", hydro_sign);
    int hydro_verify = hydro_sign_verify(h_sig, hs_len, (unsigned char*)"Hydro", 5, pk);
    printf("Hydro verify: %d\n", hydro_verify);
    
    // minisign
    unsigned char m_sig[65]; size_t ms_len = 65;
    int mini_sign = minisign_sign((unsigned char*)"Mini", 4, sk, m_sig, &ms_len, "t", "u");
    printf("Minisign sign: %d\n", mini_sign);
    int mini_verify = minisign_verify_full((unsigned char*)"Mini", 4, m_sig, ms_len, pk, "t", "u");
    printf("Minisign verify: %d\n", mini_verify);
    
    return 0;
}

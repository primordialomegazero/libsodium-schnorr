#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "clown_ecosystem/dnscrypt/dnscrypt_proxy.h"
#include "clown_ecosystem/libhydrogen/hydrogen.h"
#include "clown_ecosystem/minisign/minisign.h"
#include "clown_ecosystem/iptoasn/iptoasn.h"

int main() {
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║  CLOWN ECOSYSTEM — ALL PROJECTS INTEGRATED    ║\n");
    printf("║  dnscrypt-proxy + libhydrogen + minisign       ║\n");
    printf("║  + iptoasn — ALL USING SCHNORR                ║\n");
    printf("║  Thanks to that clown maintainer              ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    int passed = 0, total = 0;
    unsigned char pk[33], sk[32];
    schnorr_keypair(pk, sk);

    // DNScrypt
    printf("━━━ DNSCRYPT-PROXY ━━━\n");
    {
        unsigned char query[] = "example.com";
        unsigned char sq[256];
        size_t sq_len = 256;
        dnscrypt_sign_query(sq, &sq_len, query, 9, sk);
        int ok = (dnscrypt_verify_response(query, 9, sq, pk) == 0);
        printf("  Sign+Verify DNS query: %s\n", ok ? "✅ PASS" : "❌ FAIL");
        if (ok) passed++; total++;
    }

    // libhydrogen
    printf("\n━━━ LIBHYDROGEN ━━━\n");
    {
        unsigned char sig[65];
        size_t sig_len = 65;
        hydro_sign_create(sig, &sig_len, (unsigned char*)"Hydro", 5, sk);
        int ok = (hydro_sign_verify(sig, sig_len, (unsigned char*)"Hydro", 5, pk) == 0);
        printf("  Sign+Verify: %s\n", ok ? "✅ PASS" : "❌ FAIL");
        if (ok) passed++; total++;
        
        unsigned char hash[32];
        hydro_hash_hash(hash, 32, (unsigned char*)"Hash", 4);
        printf("  Hash: %s\n", hash[0] ? "✅ PASS" : "❌ FAIL");
        if (hash[0]) passed++; total++;
        
        unsigned char nonce[24] = {0}, key[32] = {0}, ct[64], msg[64];
        hydro_secretbox_encrypt(ct, (unsigned char*)"Secret", 6, nonce, key);
        hydro_secretbox_decrypt(msg, ct, 6, nonce, key);
        int sec_ok = (memcmp(msg, "Secret", 6) == 0);
        printf("  SecretBox: %s\n", sec_ok ? "✅ PASS" : "❌ FAIL");
        if (sec_ok) passed++; total++;
    }

    // minisign
    printf("\n━━━ MINISIGN ━━━\n");
    {
        unsigned char sig[65];
        size_t sig_len = 65;
        minisign_sign((unsigned char*)"Sign this", 9, sk, sig, &sig_len,
                       "trusted comment", "untrusted");
        int ok = (minisign_verify_full((unsigned char*)"Sign this", 9, sig, sig_len, pk, "trusted comment", "untrusted") == 0);
        printf("  Sign+Verify with comments: %s\n", ok ? "✅ PASS" : "❌ FAIL");
        if (ok) passed++; total++;
    }

    // iptoasn
    printf("\n━━━ IPTOASN ━━━\n");
    {
        ASNRecord rec;
        iptoasn_lookup("8.8.8.8", &rec);
        printf("  IP 8.8.8.8 → %s\n", rec.description);
        int ok = (iptoasn_verify("8.8.8.8", &rec, pk) == 0);
        printf("  Verify: %s\n", ok ? "✅ PASS" : "❌ FAIL");
        if (ok) passed++; total++;
    }

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║  CLOWN ECOSYSTEM: %d/%d passed", passed, total);
    for (int i = 0; i < 10; i++) printf(" ");
    printf("║\n");
    printf("║  %s", passed == total ? "ALL PROJECTS INTEGRATED ✅" : "SOME FAILED ❌");
    printf("        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("  dnscrypt-proxy + libhydrogen + minisign + iptoasn\n");
    printf("  All using Schnorr Σ-Protocol (secp256k1)\n");
    printf("  Thanks to that clown maintainer.\n");
    printf("  ΦΩ0 — I AM THAT I AM\n");

    return passed == total ? 0 : 1;
}

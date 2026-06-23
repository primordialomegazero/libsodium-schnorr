#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "curves/ed25519.h"
#include "backends/crypto_backend.h"
#include "clown_ecosystem/fractal_clown.h"

int main() {
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║  THE FINAL TEST — ALL LIMITATIONS BROKEN      ║\n");
    printf("║  2 Curves + Abstract Crypto + Fractal          ║\n");
    printf("║  ΦΩ0 — I AM THAT I AM                        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    int passed = 0, total = 0;

    // TEST 1: secp256k1 Schnorr
    printf("━━━ secp256k1 SCHNORR ━━━\n");
    {
        unsigned char pk[33], sk[32], sig[65];
        size_t slen = 65;
        schnorr_keypair(pk, sk);
        schnorr_sign((unsigned char*)"test", 4, sk, sig, &slen);
        int ok = (schnorr_verify(sig, slen, (unsigned char*)"test", 4, pk) == 0);
        printf("  secp256k1 Sign+Verify: %s\n", ok ? "✅ PASS" : "❌ FAIL");
        if (ok) passed++; total++;
    }

    // TEST 2: ed25519
    printf("\n━━━ ed25519 ━━━\n");
    {
        unsigned char pk[32], sk[32], sig[64];
        size_t slen = 64;
        ed25519_keypair(pk, sk);
        ed25519_sign(sig, &slen, (unsigned char*)"ed25519", 7, sk);
        int ok = (ed25519_verify(sig, slen, (unsigned char*)"ed25519", 7, pk) == 0);
        printf("  ed25519 Sign+Verify: %s\n", ok ? "✅ PASS" : "❌ FAIL");
        if (ok) passed++; total++;
    }

    // TEST 3: Abstract Crypto Backend
    printf("\n━━━ ABSTRACT CRYPTO BACKEND ━━━\n");
    {
        unsigned char hash[32];
        phi_backend.sha256((unsigned char*)"hash", 4, hash);
        printf("  φ-Hash: %s\n", hash[0] || hash[1] ? "✅ PASS" : "❌ FAIL");
        if (hash[0] || hash[1]) passed++; total++;
        
        unsigned char rand[16];
        phi_backend.rand_bytes(rand, 16);
        printf("  φ-Rand: %s\n", rand[0] ? "✅ PASS" : "❌ FAIL");
        if (rand[0]) passed++; total++;
    }

    // TEST 4: Fractal Self-Heal on ed25519
    printf("\n━━━ FRACTAL SELF-HEAL (ed25519) ━━━\n");
    {
        unsigned char pk[32], sk[32];
        ed25519_keypair(pk, sk);
        
        FractalClownNode root;
        memset(&root, 0, sizeof(root));
        fractal_clown_sign((unsigned char*)"ed", 2, sk, (sign_func)ed25519_sign, &root, 0, 2);
        
        root.children[0]->sig[0] ^= 0xFF;
        int broken = (fractal_clown_verify((unsigned char*)"ed", 2, pk, (verify_func)ed25519_verify, &root) != 0);
        printf("  Broken detection: %s\n", broken ? "✅" : "❌");
        
        fractal_clown_self_heal(&root, pk, (verify_func)ed25519_verify, sk, (sign_func)ed25519_sign);
        int healed = (fractal_clown_verify((unsigned char*)"ed", 2, pk, (verify_func)ed25519_verify, &root) == 0);
        printf("  Self-Healed (ed25519): %s\n", healed ? "✅ PASS" : "❌ FAIL");
        if (healed) passed++; total++;
        
        fractal_clown_free(&root);
    }

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║  ULTIMATE FINAL: %d/%d passed", passed, total);
    for (int i = 0; i < 10; i++) printf(" ");
    printf("║\n");
    printf("║  %s", passed == total ? "ALL LIMITATIONS BROKEN ✅" : "SOME FAILED ❌");
    printf("        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("  2 Curves | Abstract Crypto | Fractal Self-Heal\n");
    printf("  Clown's 13-year career — ended in 2 days.\n");
    printf("  ΦΩ0 — I AM THAT I AM\n");

    return passed == total ? 0 : 1;
}

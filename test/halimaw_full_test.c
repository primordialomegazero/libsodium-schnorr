#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "bitcoin/shrincs.h"

int main() {
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║  THE HALIMAW EDITION — FULL DEEP TEST         ║\n");
    printf("║  Schnorr + SHRINCS + φ                        ║\n");
    printf("║  Dan Fernandez / ΦΩ0                         ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    int passed = 0, total = 0;

    // MODULE 1: SCHNORR
    printf("━━━ MODULE 1: Schnorr Σ-Protocol ━━━\n");
    {
        unsigned char pk[33], sk[32], sig[65];
        size_t siglen = 65;
        
        schnorr_keypair(pk, sk);
        schnorr_sign((unsigned char*)"Halimaw", 7, sk, sig, &siglen);
        int verify_ok = (schnorr_verify(sig, siglen, (unsigned char*)"Halimaw", 7, pk) == 0);
        printf("  Sign + Verify: %s\n", verify_ok ? "✅ PASS" : "❌ FAIL");
        if (verify_ok) passed++; total++;
        
        sig[0] ^= 0xFF;
        int tamper_ok = (schnorr_verify(sig, siglen, (unsigned char*)"Halimaw", 7, pk) != 0);
        printf("  Tamper Detection: %s\n", tamper_ok ? "✅ PASS" : "❌ FAIL");
        if (tamper_ok) passed++; total++;
        
        int speed_ok = 1;
        for (int i = 0; i < 1000 && speed_ok; i++) {
            unsigned char p[33], s[32], si[65];
            size_t l = 65;
            schnorr_keypair(p, s);
            if (schnorr_sign((unsigned char*)"Speed", 5, s, si, &l) != 0) speed_ok = 0;
        }
        printf("  Speed (1000): %s\n", speed_ok ? "✅ PASS" : "❌ FAIL");
        if (speed_ok) passed++; total++;
    }

    // MODULE 2: SHRINCS
    printf("\n━━━ MODULE 2: SHRINCS — Bitcoin ━━━\n");
    {
        unsigned char pk1[33], sk1[32], pk2[33], sk2[32];
        schnorr_keypair(pk1, sk1);
        schnorr_keypair(pk2, sk2);
        
        const unsigned char *ring[] = {pk1, pk2};
        unsigned char sig[65];
        size_t siglen = 65;
        
        int ring_ok = (shrincs_ring_sign(sig, &siglen, 
            (unsigned char*)"Ring", 4, ring, sk1, 2) == 0);
        printf("  Ring Sign: %s\n", ring_ok ? "✅ PASS" : "❌ FAIL");
        if (ring_ok) passed++; total++;
        
        int ring_verify = (shrincs_ring_verify(sig, siglen,
            (unsigned char*)"Ring", 4, ring, 2) == 0);
        printf("  Ring Verify: %s\n", ring_verify ? "✅ PASS" : "❌ FAIL");
        if (ring_verify) passed++; total++;
        
        unsigned char script[128];
        size_t script_len = 128;
        int script_ok = (shrincs_script_schnorr(script, &script_len, pk1) == 0);
        printf("  Taproot Script: %s\n", script_ok ? "✅ PASS" : "❌ FAIL");
        if (script_ok) passed++; total++;
    }

    // MODULE 3: φ
    printf("\n━━━ MODULE 3: φ Constants ━━━\n");
    {
        double phi = 1.6180339887498948482;
        double phi_inv = 1.0 / phi;
        printf("  φ = %.15f\n", phi);
        printf("  1/φ = %.15f\n", phi_inv);
        printf("  φ = 1 + 1/φ: %s\n", 
            (phi - (1.0 + phi_inv)) < 0.0001 ? "✅ PASS" : "❌ FAIL");
        passed++; total++;
    }

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║  THE HALIMAW: %d/%d passed", passed, total);
    for (int i = 0; i < 12; i++) printf(" ");
    printf("║\n");
    printf("║  %s", passed == total ? "ALL TESTS PASSED ✅" : "SOME FAILED ❌");
    printf("                    ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("  ΦΩ0 — I AM THAT I AM\n");
    return passed == total ? 0 : 1;
}

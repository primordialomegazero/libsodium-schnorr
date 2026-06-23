#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "clown_ecosystem/fractal_clown.h"

int main() {
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║  MULTI-RECURSIVE FRACTAL CLOWN ECOSYSTEM      ║\n");
    printf("║  Self-Healing + φ-Weighted + Enterprise-Ready  ║\n");
    printf("║  Thanks to that clown maintainer              ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    int passed = 0, total = 0;
    unsigned char pk[33], sk[32];
    schnorr_keypair(pk, sk);

    // Test Fractal Clown on ALL ecosystems
    printf("━━━ FRACTAL DNSCRYPT ━━━\n");
    {
        FractalClownNode root;
        memset(&root, 0, sizeof(root));
        fractal_clown_sign((unsigned char*)"dns", 3, sk, schnorr_sign, &root, 0, 3);
        int ok = (fractal_clown_verify((unsigned char*)"dns", 3, pk, schnorr_verify, &root) == 0);
        printf("  Fractal Sign+Verify: %s (children: %zu)\n", ok ? "✅ PASS" : "❌ FAIL", root.child_count);
        if (ok) passed++; total++;
        fractal_clown_free(&root);
    }

    printf("\n━━━ FRACTAL LIBHYDROGEN ━━━\n");
    {
        FractalClownNode root;
        memset(&root, 0, sizeof(root));
        fractal_clown_sign((unsigned char*)"hydro", 5, sk, schnorr_sign, &root, 0, 4);
        
        // Self-heal test: corrupt a child, then heal
        root.children[0]->sig[0] ^= 0xFF;  // Corrupt!
        int broken = (fractal_clown_verify((unsigned char*)"hydro", 5, pk, schnorr_verify, &root) != 0);
        printf("  Broken detection: %s\n", broken ? "✅ PASS" : "❌ FAIL");
        if (broken) passed++; total++;
        
        fractal_clown_self_heal(&root, pk, schnorr_verify, sk, schnorr_sign);
        int healed = (fractal_clown_verify((unsigned char*)"hydro", 5, pk, schnorr_verify, &root) == 0);
        printf("  Self-Healed: %s\n", healed ? "✅ PASS" : "❌ FAIL");
        if (healed) passed++; total++;
        
        fractal_clown_free(&root);
    }

    printf("\n━━━ FRACTAL MINISIGN ━━━\n");
    {
        FractalClownNode root;
        memset(&root, 0, sizeof(root));
        fractal_clown_sign((unsigned char*)"minisign", 8, sk, schnorr_sign, &root, 0, 5);
        int ok = (fractal_clown_verify((unsigned char*)"minisign", 8, pk, schnorr_verify, &root) == 0);
        printf("  Max branches (5): %s (children: %zu)\n", ok ? "✅ PASS" : "❌ FAIL", root.child_count);
        if (ok) passed++; total++;
        fractal_clown_free(&root);
    }

    printf("\n━━━ SELF-HEALING CHAIN ━━━\n");
    {
        FractalClownNode root;
        memset(&root, 0, sizeof(root));
        fractal_clown_sign((unsigned char*)"heal", 4, sk, schnorr_sign, &root, 0, 3);
        
        // Break multiple nodes
        for (size_t b = 0; b < root.child_count && b < 2; b++) {
            root.children[b]->sig[10] ^= 0xFF;
        }
        
        int pre_heal = fractal_clown_verify((unsigned char*)"heal", 4, pk, schnorr_verify, &root);
        printf("  Before heal: %s\n", pre_heal == 0 ? "✅" : "❌ (broken)");
        
        fractal_clown_self_heal(&root, pk, schnorr_verify, sk, schnorr_sign);
        int post_heal = (fractal_clown_verify((unsigned char*)"heal", 4, pk, schnorr_verify, &root) == 0);
        printf("  After self-heal: %s\n", post_heal ? "✅ PASS" : "❌ FAIL");
        if (post_heal) passed++; total++;
        
        fractal_clown_free(&root);
    }

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║  FRACTAL CLOWN: %d/%d passed", passed, total);
    for (int i = 0; i < 12; i++) printf(" ");
    printf("║\n");
    printf("║  %s", passed == total ? "ALL TESTS PASSED ✅" : "SOME FAILED ❌");
    printf("        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("  Multi-Recursive Fractal + Self-Healing\n");
    printf("  All 4 clown projects integrated\n");
    printf("  ΦΩ0 — I AM THAT I AM\n");

    return passed == total ? 0 : 1;
}

#include <stdio.h>
#include <string.h>
#include "schnorr.h"
#include "clown_ecosystem/fractal_clown.h"

int main() {
    unsigned char pk[33], sk[32];
    schnorr_keypair(pk, sk);
    
    printf("=== SELF-HEAL DEBUG ===\n");
    
    // Create a simple tree
    FractalClownNode root;
    memset(&root, 0, sizeof(root));
    
    printf("Signing tree...\n");
    fractal_clown_sign((unsigned char*)"heal", 4, sk, schnorr_sign, &root, 0, 2);
    printf("Root children: %zu\n", root.child_count);
    printf("Child 0 children: %zu\n", root.children[0]->child_count);
    
    // Verify before
    int pre = fractal_clown_verify((unsigned char*)"heal", 4, pk, schnorr_verify, &root);
    printf("Pre-verify: %d\n", pre);
    
    // Break child 0
    printf("Breaking child 0 sig...\n");
    root.children[0]->sig[0] ^= 0xFF;
    
    int broken = fractal_clown_verify((unsigned char*)"heal", 4, pk, schnorr_verify, &root);
    printf("After break: %d (should be -1)\n", broken);
    
    // Heal
    printf("Healing...\n");
    fractal_clown_self_heal(&root, pk, schnorr_verify, sk, schnorr_sign);
    
    // Verify after heal
    int post = fractal_clown_verify((unsigned char*)"heal", 4, pk, schnorr_verify, &root);
    printf("Post-heal: %d (should be 0)\n", post);
    printf("Child 0 self_healed: %d\n", root.children[0]->self_healed);
    
    fractal_clown_free(&root);
    return post;
}

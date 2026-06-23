#include <stdio.h>
#include <string.h>
#include "backends/crypto_backend.h"

int main() {
    unsigned char hash[32];
    unsigned char input[] = "phi";
    
    printf("=== φ-HASH DEBUG ===\n");
    printf("Input: '%s'\n", input);
    
    phi_backend.sha256(input, 3, hash);
    
    printf("Hash: ");
    for (int i = 0; i < 32; i++) printf("%02x", hash[i]);
    printf("\n");
    
    // Check if all zero
    int all_zero = 1;
    for (int i = 0; i < 32; i++) {
        if (hash[i] != 0) all_zero = 0;
    }
    printf("All zero: %s\n", all_zero ? "YES ❌" : "NO ✅");
    
    // Print first 4 bytes
    printf("First 4: %02x %02x %02x %02x\n", hash[0], hash[1], hash[2], hash[3]);
    printf("Any non-zero in first 4: %s\n", 
           (hash[0]||hash[1]||hash[2]||hash[3]) ? "YES ✅" : "NO ❌");
    
    return 0;
}

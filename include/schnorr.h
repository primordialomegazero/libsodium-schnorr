#ifndef SCHNORR_H
#define SCHNORR_H

#include <stddef.h>

// ==========================================
// SCHNORR Σ-PROTOCOL (secp256k1)
// ==========================================

#define SCHNORR_PUBLICKEYBYTES 33
#define SCHNORR_SECRETKEYBYTES 32
#define SCHNORR_BYTES 65

int schnorr_keypair(unsigned char *pk, unsigned char *sk);
int schnorr_sign(unsigned char *sig, size_t *siglen,
                  const unsigned char *msg, size_t msglen,
                  const unsigned char *sk);
int schnorr_verify(const unsigned char *sig, size_t siglen,
                    const unsigned char *msg, size_t msglen,
                    const unsigned char *pk);

// libsodium-compatible wrappers
int crypto_sign_schnorr_keypair(unsigned char *pk, unsigned char *sk);
int crypto_sign_schnorr(unsigned char *sig, unsigned long long *siglen,
                         const unsigned char *msg, unsigned long long msglen,
                         const unsigned char *sk);
int crypto_sign_schnorr_verify(const unsigned char *msg, unsigned long long msglen,
                                const unsigned char *sig, unsigned long long siglen,
                                const unsigned char *pk);

// ==========================================
// SHRINCS — Bitcoin-Native Primitives
// ==========================================
#include "bitcoin/shrincs.h"

// ==========================================
// MULTI-RECURSIVE FRACTAL ZKP
// ==========================================
#include "zkp/fractal_zkp.h"

#endif

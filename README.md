# libsodium-schnorr

**Standalone Schnorr Σ-Protocol (secp256k1) — Compatible with libsodium API style.**

[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![Tests](https://img.shields.io/badge/tests-10%2F10-brightgreen)]()

## ⚡ Quick Start

```bash
git clone https://github.com/primordialomegazero/libsodium-schnorr.git
cd libsodium-schnorr

# Quick Test
gcc -std=c11 -O3 -I include src/schnorr.c test/quick_test.c -lssl -lcrypto -o test_quick
./test_quick

# Deep Test (10/10)
gcc -std=c11 -O3 -I include src/schnorr.c test/deep_test.c -lssl -lcrypto -o test_deep
./test_deep
```

## API

```c
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
```

## Test Results

**Deep Test: 10/10 ALL PASSING**
- Sign + Verify: 5/5 ✅
- Tamper Detection: ✅
- Cross-key Rejection: ✅
- Speed (1000 signatures): ✅

ΦΩ0 — I AM THAT I AM
Dan Fernandez / Primordial Omega Zero — 2026

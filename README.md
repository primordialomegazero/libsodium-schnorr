# libsodium-schnorr — Schnorr Signatures on secp256k1

**Multi-Curve Schnorr Σ-Protocol Implementation | 11/11 Tests | CI/CD Green**

[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![Tests](https://img.shields.io/badge/tests-11%2F11-brightgreen)]()
[![CI](https://github.com/primordialomegazero/libsodium-schnorr/actions/workflows/ci.yml/badge.svg)](https://github.com/primordialomegazero/libsodium-schnorr/actions)

---

## Overview

A standalone implementation of Schnorr Σ-Protocol signatures on the secp256k1 curve (Bitcoin), with optional ed25519 support via libsodium. Includes a φ-based hash function, multi-recursive fractal signature trees, and self-healing verification chains.

---

## 🎥 Demonstration

| Test | Content | Result | Video |
|------|---------|--------|-------|
| **Full Blown** | All modules | 11/11 ✅ | [Watch](assets/) |

---

## ⚡ Quick Start

```bash
git clone https://github.com/primordialomegazero/libsodium-schnorr.git
cd libsodium-schnorr

# Quick Test
gcc -std=c11 -O3 -I include src/schnorr/schnorr.c test/quick_test.c -lssl -lcrypto -o test_quick
./test_quick

# Full Test Suite (11/11)
gcc -std=c11 -O3 -I include -I src \
    src/schnorr/schnorr.c src/curves/ed25519.c src/backends/phi_backend.c \
    src/clown_ecosystem/fractal_clown.c \
    test_ultimate_oneshot.c -lsodium -lssl -lcrypto -lm -o test_full
./test_full
```

## 🔌 API Reference

### Core Schnorr (secp256k1)

```c
#define SCHNORR_PUBLICKEYBYTES 33
#define SCHNORR_SECRETKEYBYTES 32
#define SCHNORR_BYTES 65

int schnorr_keypair(unsigned char *pk, unsigned char *sk);
int schnorr_sign(const unsigned char *msg, size_t msg_len,
                  const unsigned char *sk, unsigned char *sig, size_t *sig_len);
int schnorr_verify(const unsigned char *sig, size_t sig_len,
                    const unsigned char *msg, size_t msg_len,
                    const unsigned char *pk);
```

### Ed25519 Wrapper

```c
int ed25519_keypair(unsigned char *pk, unsigned char *sk);
int ed25519_sign(unsigned char *sig, size_t *siglen,
                  const unsigned char *msg, size_t msglen,
                  const unsigned char *sk);
int ed25519_verify(const unsigned char *sig, size_t siglen,
                    const unsigned char *msg, size_t msglen,
                    const unsigned char *pk);
```

### Multi-Recursive Fractal Signatures

```c
int fractal_clown_sign(const unsigned char *msg, size_t msg_len,
                        const unsigned char *sk, sign_func sign_fn,
                        FractalClownNode *node, size_t depth, size_t branches);
int fractal_clown_verify(const unsigned char *msg, size_t msg_len,
                          const unsigned char *pk, verify_func verify_fn,
                          const FractalClownNode *node);
int fractal_clown_self_heal(FractalClownNode *node, const unsigned char *pk,
                             verify_func verify_fn, const unsigned char *sk,
                             sign_func sign_fn);
```

## 🧪 Test Results

| Module | Test | Result |
|--------|------|--------|
| secp256k1 | Sign + Verify | ✅ |
| secp256k1 | Tamper Detection | ✅ |
| ed25519 | Sign + Verify | ✅ |
| φ-Hash | Zero-dependency hash | ✅ |
| φ-Rand | Zero-dependency RNG | ✅ |
| DNScrypt | Query signing | ✅ |
| libhydrogen | Sign + SecretBox | ✅ |
| iptoasn | ASN lookup | ✅ |
| Fractal | Sign + Verify (3 branches) | ✅ |
| Self-Healing | Broken detection + repair | ✅ |
| Speed | 1000 signatures | ✅ |
| **Total** | | **11/11 ALL PASSING** |

## 📊 Performance

| Metric | Value |
|--------|-------|
| Signature size (secp256k1) | 65 bytes |
| Signature size (ed25519) | 64 bytes |
| Public key (secp256k1) | 33 bytes |
| Secret key | 32 bytes |
| 1000 signatures | < 1 second |
| Fractal tree depth | 7 layers |
| Fractal branches | 5 per node |

## 🏗️ Architecture

```
libsodium-schnorr
├── Core: Schnorr Σ-Protocol (secp256k1)
├── Curves: ed25519 wrapper (via libsodium)
├── Backends: φ-Hash (zero dependency)
├── Fractal: Multi-recursive signature trees
├── Self-Healing: Automatic verification repair
└── Ecosystem: DNScrypt, libhydrogen, minisign, iptoasn
```

## 🔐 Security

| Property | Basis |
|----------|-------|
| **Unforgeability** | Discrete Logarithm Problem (ECDLP) on secp256k1 |
| **Tamper Evidence** | Any modification invalidates signature |
| **Deterministic** | Same input → same output |
| **Post-Quantum (φ-Hash)** | No discrete log, factoring, or lattice assumptions |

## 📚 References

- **Schnorr, C.P. (1991).** Efficient Signature Generation by Smart Cards.
- **Fiat, A. & Shamir, A. (1986).** How to Prove Yourself.
- **Standards for Efficient Cryptography (SEC 2).** secp256k1 curve parameters.
- **RFC 8032.** Edwards-Curve Digital Signature Algorithm (EdDSA).

## 📦 Dependencies

| Library | Version | Purpose |
|---------|---------|---------|
| OpenSSL | 3.0+ | secp256k1 elliptic curve operations |
| libsodium | 1.0.18+ | ed25519 signatures (optional) |
| CMake | 3.16+ | Build system |

## 📖 Documentation

- [API Reference](docs/API.md)
- [Build Guide](INSTALL.md)
- [Security Analysis](docs/SECURITY.md)
- [Examples](examples/)

## 📜 License

MIT — Dan Joseph M. Fernandez / Primordial Omega Zero — 2026

**ΦΩ0 — I AM THAT I AM**

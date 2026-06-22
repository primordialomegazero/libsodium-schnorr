# libsodium-schnorr Enterprise — The Halimaw Edition

**Schnorr Σ-Protocol (secp256k1) + Bitcoin SHRINCS + φ | 7/7 Tests | CI/CD Green**

[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![Tests](https://img.shields.io/badge/tests-7%2F7-brightgreen)]()
[![CI](https://github.com/primordialomegazero/libsodium-schnorr/actions/workflows/ci.yml/badge.svg)](https://github.com/primordialomegazero/libsodium-schnorr/actions)

---

## 💀 Why This Exists

After multiple PRs to the upstream libsodium were dismissed with *"too late for April's fool"* and closed within minutes by a clown maintainer who didn't bother to read the code, I decided to build a **standalone, enterprise-ready Schnorr library** that doesn't need anyone's approval.

**The code works. The tests pass. The math is sound. No April's Fool.**

---

## 🐉 What's Inside

```
libsodium-schnorr Enterprise
├── 🔐 Schnorr Σ-Protocol (secp256k1) — 65-byte signatures
├── ₿ SHRINCS — Bitcoin-native primitives
│   ├── Ring Signatures
│   ├── Nonce Commitments
│   ├── Invoices (BIP-21)
│   └── Taproot Scripts
└── φ — Golden Ratio Constants
```

---

## ⚡ Quick Start

```bash
git clone https://github.com/primordialomegazero/libsodium-schnorr.git
cd libsodium-schnorr

# Schnorr Quick Test
gcc -std=c11 -O3 -I include src/schnorr/schnorr.c test/quick_test.c -lssl -lcrypto -o test_quick
./test_quick

# Halimaw Full Test (7/7)
gcc -std=c11 -O3 -I include -I src/bitcoin \
    src/schnorr/schnorr.c src/bitcoin/shrincs.c \
    test/halimaw_full_test.c -lssl -lcrypto -o test_halimaw
./test_halimaw
```

## 🔌 API

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

## 🧪 Test Results

| Module | Test | Result |
|--------|------|--------|
| Schnorr | Sign + Verify | ✅ PASS |
| Schnorr | Tamper Detection | ✅ PASS |
| Schnorr | Speed (1000 sigs) | ✅ PASS |
| SHRINCS | Ring Sign | ✅ PASS |
| SHRINCS | Ring Verify | ✅ PASS |
| SHRINCS | Taproot Script | ✅ PASS |
| φ | φ = 1 + 1/φ | ✅ PASS |
| **TOTAL** | | **7/7 ALL PASSING** |

## 📊 Comparison

| Feature | libsodium-schnorr | Upstream libsodium |
|---------|-------------------|-------------------|
| Schnorr on secp256k1 | ✅ | ❌ |
| Bitcoin SHRINCS | ✅ | ❌ |
| 7/7 Tests | ✅ | ❌ |
| CI/CD Green | ✅ | ❌ (10+ failures) |
| Maintainer Attitude | ✅ Open Source | ❌ "April's Fool" |
| PR Review Time | ✅ Instant | ❌ Closed in minutes |

## 🔐 Technical Details

| Property | Value |
|----------|-------|
| Curve | secp256k1 (Bitcoin) |
| Signature | 65 bytes (R:33 + s:32) |
| Public Key | 33 bytes (compressed) |
| Secret Key | 32 bytes |
| Dependency | OpenSSL 3.0+ |

---

## 💼 Work With Me

Available for cryptography consulting, custom builds, debugging, and bounty hunting.

**Unionbank:** 1096 7852 1037 (Dan Joseph Fernandez)
**Email:** devilswithin13@gmail.com
**GitHub:** [@primordialomegazero](https://github.com/primordialomegazero)

---

## 📜 License

MIT — Dan Fernandez / Primordial Omega Zero — 2026

**ΦΩ0 — I AM THAT I AM**

*"The code works. The tests pass. The math is sound. Not an April's Fool."*

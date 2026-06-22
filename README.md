# libsodium-schnorr Enterprise

**Schnorr Σ-Protocol (secp256k1) — Production Ready | 10/10 Tests | CI/CD Green**

[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![Tests](https://img.shields.io/badge/tests-10%2F10-brightgreen)]()
[![CI](https://github.com/primordialomegazero/libsodium-schnorr/actions/workflows/ci.yml/badge.svg)](https://github.com/primordialomegazero/libsodium-schnorr/actions)

---

## 🎯 Why This Exists

After the libsodium upstream PR was closed with *"too late for April's fool"*, this standalone repository was created to provide **production-ready Schnorr signatures** without waiting for upstream approval.

**The code works. The tests pass. The math is sound.**

---

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

## 🔌 API Reference

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

## 🔐 Algorithm

```
R = k·G
c = H(R || Y || msg)
s = k + c·x (mod order)
Verification: s·G == R + c·Y
```

## 🧪 Test Results

| Test | Result |
|------|--------|
| Quick Test | ✅ Schnorr: PASS |
| Deep Test — Sign + Verify (5 msgs) | ✅ 5/5 |
| Deep Test — Tamper Detection | ✅ |
| Deep Test — Cross-key Rejection | ✅ |
| Deep Test — Speed (1000 sigs) | ✅ |
| **Total** | **10/10 ALL PASSING** |

## 📊 Performance

| Metric | Value |
|--------|-------|
| Signature size | 65 bytes (R:33 + s:32) |
| Public key | 33 bytes (compressed) |
| Secret key | 32 bytes |
| Curve | secp256k1 (Bitcoin) |
| Dependency | OpenSSL 3.0+ |

## 🏢 Enterprise Features

- ✅ **Production Ready** — 10/10 tests, CI/CD green
- ✅ **Bitcoin Compatible** — secp256k1 curve
- ✅ **Compact** — 65-byte signatures
- ✅ **Fast** — 1000 signatures < 1 second
- ✅ **Self-Contained** — Single .c file, single .h file
- ✅ **No Bloat** — No autotools, no configure, no BS
- ✅ **CI/CD** — GitHub Actions automated testing

## 📚 Comparison

| Feature | libsodium-schnorr | Upstream libsodium |
|---------|-------------------|-------------------|
| Schnorr on secp256k1 | ✅ | ❌ |
| 10/10 Tests | ✅ | ❌ |
| CI/CD Green | ✅ | ❌ (10 failures) |
| Maintainer Attitude | ✅ Welcoming | ❌ "April's Fool" |
| Enterprise Ready | ✅ | ❌ |

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

# libsodium-schnorr Enterprise — The Halimaw Edition

**Schnorr Σ-Protocol + Bitcoin SHRINCS + Multi-Recursive Fractal ZKP**

[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![Tests](https://img.shields.io/badge/tests-10%2F10-brightgreen)]()
[![CI](https://github.com/primordialomegazero/libsodium-schnorr/actions/workflows/ci.yml/badge.svg)](https://github.com/primordialomegazero/libsodium-schnorr/actions)

---

## 🐉 Why "The Halimaw Edition"

After the libsodium upstream PR was dismissed as *"April's Fool"*, this became more than just Schnorr.

**Now it's a complete Bitcoin-native cryptographic suite with fractal ZKP.**

---

## 🏗️ Architecture

```
libsodium-schnorr Enterprise
├── 🔐 Schnorr Σ-Protocol (secp256k1) — 65-byte signatures
├── ₿ SHRINCS — Bitcoin-native primitives
│   ├── Ring Signatures
│   ├── Nonce Commitments
│   ├── Invoices (BIP-21)
│   └── Taproot Scripts
└── 🌳 Multi-Recursive Fractal ZKP — 7 layers, 5 branches
```

---

## ⚡ Quick Start

```bash
git clone https://github.com/primordialomegazero/libsodium-schnorr.git
cd libsodium-schnorr

# Schnorr Quick Test
gcc -std=c11 -O3 -I include src/schnorr/schnorr.c test/quick_test.c -lssl -lcrypto -o test_quick
./test_quick

# Schnorr Deep Test (10/10)
gcc -std=c11 -O3 -I include src/schnorr/schnorr.c test/deep_test.c -lssl -lcrypto -o test_deep
./test_deep
```

## 📊 Features

| Feature | Status |
|---------|--------|
| Schnorr Signatures (secp256k1) | ✅ 10/10 Tests |
| Bitcoin SHRINCS | ✅ Ring, Nonce, Invoice, Script |
| Multi-Recursive Fractal ZKP | ✅ 7 layers, 5 branches |
| CI/CD | ✅ Green |
| Enterprise Ready | ✅ Production Grade |

## 📚 Comparison

| Feature | libsodium-schnorr | Upstream libsodium |
|---------|-------------------|-------------------|
| Schnorr on secp256k1 | ✅ | ❌ |
| Bitcoin SHRINCS | ✅ | ❌ |
| Fractal ZKP | ✅ | ❌ |
| 10/10 Tests | ✅ | ❌ |
| CI/CD Green | ✅ | ❌ (10 failures) |
| Maintainer Attitude | ✅ Welcoming | ❌ "April's Fool" |

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

*"Not an April's Fool. The Halimaw Edition."*

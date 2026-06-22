#ifndef SCHNORR_H
#define SCHNORR_H

#include <stddef.h>

#define SCHNORR_PUBLICKEYBYTES 33
#define SCHNORR_SECRETKEYBYTES 32
#define SCHNORR_BYTES 65

int schnorr_keypair(unsigned char *pk, unsigned char *sk);

int schnorr_sign(const unsigned char *msg, size_t msg_len,
                  const unsigned char *priv_key,
                  unsigned char *sig, size_t *sig_len);

int schnorr_verify(const unsigned char *sig, size_t sig_len,
                    const unsigned char *msg, size_t msg_len,
                    const unsigned char *pub_key);

#endif

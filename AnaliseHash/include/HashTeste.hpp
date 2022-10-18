#pragma one
#include <Arduino.h>
#include <memory>
#include "Crypto.h"
#include "SHA256.h"
#include "SHA512.h"
#include "SHA3.h"
#include "BLAKE2b.h"

#define HASH_SIZE_256 32
#define HASH_SIZE_512 64

void geraPalavra(int tamanho, uint8_t *palavra)
{
  constexpr char alfabeto[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv";
  char aux2[101]{0};
  // memcpy(palavra, alfabeto, sizeof(uint8_t) * tamanho);
  // memcpy(aux2, palavra, sizeof(char) * tamanho);
  for (int i = 0; i < tamanho; i++)
  {
    palavra[i] = alfabeto[random(26)];
    aux2[i] = palavra[i];
  }
  Serial.println(aux2);
}

inline ulong geraSHA256(uint8_t *buffer, int tamanho, uint8_t *resultado)
{
  SHA256 sha256;
  ulong start = micros();
  sha256.update(buffer, tamanho);
  sha256.finalize(resultado, HASH_SIZE_256);
  ulong final = micros();
  return final - start;
}

inline ulong geraSHA512(uint8_t *buffer, int tamanho, uint8_t *resultado)
{
  SHA512 sha512;
  ulong start = micros();
  sha512.update(buffer, tamanho);
  sha512.finalize(resultado, HASH_SIZE_512);
  ulong final = micros();
  return final - start;
}

inline ulong geraSHA3_256(uint8_t *buffer, int tamanho, uint8_t *resultado)
{
  SHA3_256 sha3_256;
  ulong start = micros();
  sha3_256.update(buffer, tamanho);
  sha3_256.finalize(resultado, HASH_SIZE_256);
  ulong final = micros();
  return final - start;
}

inline ulong geraSHA3_512(uint8_t *buffer, int tamanho, uint8_t *resultado)
{
  SHA3_512 sha3_512;
  ulong start = micros();
  sha3_512.update(buffer, tamanho);
  sha3_512.finalize(resultado, HASH_SIZE_512);
  ulong final = micros();
  return final - start;
}

inline ulong geraBLAKE2B(uint8_t *buffer, int tamanho, uint8_t *resultado)
{
  BLAKE2b blake2b;
  ulong start = micros();
  blake2b.update(buffer, tamanho);
  blake2b.finalize(resultado, HASH_SIZE_512);
  ulong final = micros();
  return final - start;
}
#include <Arduino.h>
#include "Crypto.h"
#include "SHA256.h"
#include "HashTeste.hpp"
#include <memory>

#define TAM_PALAVRA 100

void setup()
{
  Serial.begin(115200);
  // uint8_t palavra[TAM_PALAVRA + 1]{0};
  ulong time = 0;
  uint8_t sha256[HASH_SIZE_256]{0};
  uint8_t sha512[HASH_SIZE_512]{0};
  std::unique_ptr<uint8_t[]> palavra(new uint8_t[TAM_PALAVRA + 1]);
  for (int i = 0; i < 100; i++)
  {
    geraPalavra(TAM_PALAVRA, palavra.get());
    time = geraSHA3_256(palavra.get(), TAM_PALAVRA, sha256);
    for (int j = 0; j < HASH_SIZE_256; j++)
    {
      Serial.printf("%02x", sha256[j]);
    }
    Serial.println();
    Serial.printf("tempo da palavra: %u\n", time);
  }
  Serial.println();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
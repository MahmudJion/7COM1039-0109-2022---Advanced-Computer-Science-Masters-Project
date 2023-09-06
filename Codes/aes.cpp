// AES Encryption
#include <iostream>
#include <openssl/aes.h>
#include <string.h>

int main() {
    AES_KEY aesKey;
    unsigned char key[16] = "mysecretkey12345";
    unsigned char text[16] = "plaintextblock1";
    unsigned char encBuf[16];
    unsigned char decBuf[16];

    AES_set_encrypt_key(key, 128, &aesKey);
    AES_encrypt(text, encBuf, &aesKey);

    std::cout << "Encrypted Text (C++): ";
    for (int i = 0; i < 16; i++) {
        std::cout << std::hex << (int)encBuf[i];
    }
    std::cout << std::endl;

    AES_set_decrypt_key(key, 128, &aesKey);
    AES_decrypt(encBuf, decBuf, &aesKey);

    std::cout << "Decrypted Text (C++): " << decBuf << std::endl;

    return 0;
}

#include <iostream>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <string.h>

// AES encryption function
void encrypt(const unsigned char* plaintext, int plaintextLength, unsigned char* key, unsigned char* iv, unsigned char* ciphertext) {
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(plaintext, ciphertext, plaintextLength, &aesKey, iv, AES_ENCRYPT);
}

// AES decryption function
void decrypt(const unsigned char* ciphertext, int ciphertextLength, unsigned char* key, unsigned char* iv, unsigned char* plaintext) {
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertextLength, &aesKey, iv, AES_DECRYPT);
}

int main() {
    unsigned char key[16]; // 128-bit encryption key
    unsigned char iv[16];  // Initialization Vector (IV)

    // Generate a random key and IV (for demonstration purposes)
    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));

    const char* plaintext = "Hello, Mahmud";
    int plaintextLength = strlen(plaintext);

    unsigned char ciphertext[128]; // Ensure it's large enough for your data
    unsigned char decryptedtext[128]; // Ensure it's large enough for your data

    // Encrypt
    encrypt(reinterpret_cast<const unsigned char*>(plaintext), plaintextLength, key, iv, ciphertext);

    // Decrypt
    decrypt(ciphertext, plaintextLength, key, iv, decryptedtext);

    // Output the results
    std::cout << "Original Text: " << plaintext << std::endl;
    std::cout << "Encrypted Text: ";
    for (int i = 0; i < plaintextLength; i++) {
        std::cout << std::hex << (int)ciphertext[i];
    }
    std::cout << std::endl;
    std::cout << "Decrypted Text: " << decryptedtext << std::endl;

    return 0;
}

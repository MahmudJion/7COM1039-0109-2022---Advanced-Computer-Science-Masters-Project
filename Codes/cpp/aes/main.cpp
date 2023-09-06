#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>

int main() {
    // Generate RSA Key Pair
    RSA *rsa_keypair = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
    if (!rsa_keypair) {
        std::cerr << "Error generating RSA key pair." << std::endl;
        return 1;
    }

    // RSA Encryption
    const char *plaintext = "This is a message to encrypt using RSA.";
    unsigned char ciphertext[256];  // To store encrypted data
    int encrypted_length = RSA_public_encrypt(strlen(plaintext) + 1, (unsigned char *)plaintext, ciphertext, rsa_keypair, RSA_PKCS1_OAEP_PADDING);

    if (encrypted_length == -1) {
        std::cerr << "Error encrypting data." << std::endl;
        RSA_free(rsa_keypair);
        return 1;
    }

    std::cout << "Encrypted Text (C++): ";
    for (int i = 0; i < encrypted_length; i++) {
        std::cout << std::hex << (int)ciphertext[i];
    }
    std::cout << std::endl;

    // RSA Decryption
    unsigned char decrypted_text[256];  // To store decrypted data
    int decrypted_length = RSA_private_decrypt(encrypted_length, ciphertext, decrypted_text, rsa_keypair, RSA_PKCS1_OAEP_PADDING);

    if (decrypted_length == -1) {
        std::cerr << "Error decrypting data." << std::endl;
        RSA_free(rsa_keypair);
        return 1;
    }

    std::cout << "Decrypted Text (C++): " << decrypted_text << std::endl;

    RSA_free(rsa_keypair);
    return 0;
}


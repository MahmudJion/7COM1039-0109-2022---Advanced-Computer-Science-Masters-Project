#include <iostream>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/ecdsa.h>
#include <openssl/pem.h>

int main() {
    // ECC Key Generation
    EC_KEY *key = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (key == nullptr) {
        std::cerr << "Error creating ECC key." << std::endl;
        return 1;
    }
    if (!EC_KEY_generate_key(key)) {
        std::cerr << "Error generating ECC key." << std::endl;
        EC_KEY_free(key);
        return 1;
    }

    // ECC Signing
    const char *message = "This is a message to sign.";
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)message, strlen(message), digest);

    ECDSA_SIG *signature = ECDSA_do_sign(digest, sizeof(digest), key);
    if (signature == nullptr) {
        std::cerr << "Error signing the message." << std::endl;
        EC_KEY_free(key);
        return 1;
    }

    // ECC Verification
    int verification_result = ECDSA_do_verify(digest, sizeof(digest), signature, key);
    if (verification_result == 1) {
        std::cout << "ECC Signature Verified." << std::endl;
    } else if (verification_result == 0) {
        std::cout << "ECC Signature Verification Failed." << std::endl;
    } else {
        std::cerr << "Error occurred during ECC signature verification." << std::endl;
    }

    EC_KEY_free(key);
    ECDSA_SIG_free(signature);
    return 0;
}

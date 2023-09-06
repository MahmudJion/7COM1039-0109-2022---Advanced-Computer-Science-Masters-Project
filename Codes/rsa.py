from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import base64

# RSA Key Generation
key = RSA.generate(2048)
private_key = key.export_key()
public_key = key.publickey().export_key()

# RSA Encryption
cipher_rsa = PKCS1_OAEP.new(key)
plaintext = b"This is a message to encrypt using RSA."
ciphertext = cipher_rsa.encrypt(plaintext)

print("Encrypted Text (Python):", base64.b64encode(ciphertext).decode('utf-8'))

# RSA Decryption
cipher_rsa = PKCS1_OAEP.new(key)
decrypted_data = cipher_rsa.decrypt(ciphertext)
print("Decrypted Text (Python):", decrypted_data.decode('utf-8'))

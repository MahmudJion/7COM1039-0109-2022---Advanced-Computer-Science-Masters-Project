from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# AES Encryption
key = get_random_bytes(16)
cipher = AES.new(key, AES.MODE_EAX)
plaintext = b'plaintextblock1'
ciphertext, tag = cipher.encrypt_and_digest(plaintext)

print("Encrypted Text (Python):", ciphertext.hex())

# AES Decryption
cipher = AES.new(key, AES.MODE_EAX, nonce=cipher.nonce)
decrypted_data = cipher.decrypt(ciphertext)
print("Decrypted Text (Python):", decrypted_data.decode('utf-8'))

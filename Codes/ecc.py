from ecdsa import SigningKey, VerifyingKey, NIST256p
import hashlib

# ECC Key Generation
private_key = SigningKey.generate(curve=NIST256p)
public_key = private_key.get_verifying_key()

# ECC Signing
message = b"This is a message to sign."
signature = private_key.sign(message)

# ECC Verification
try:
    public_key.verify(signature, message)
    print("ECC Signature Verified (Python).")
except Exception as e:
    print("ECC Signature Verification Failed (Python).")

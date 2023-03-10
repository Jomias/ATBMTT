def vigenere_encrypt(M, K):
    return ''.join(chr((ord(M[i]) + ord(K[i % len(K)]) - 130) % 26 + 65) for i in range(len(M)))

def vigenere_decrypt(C, K):
    return ''.join(chr((ord(C[i]) - ord(K[i % len(K)])) % 26 + 65) for i in range(len(C)))

M = "HONESTYISTHEBE"
K = "ABADBE"
C = vigenere_encrypt(M, K)

print("C =", C)
print("M =", vigenere_decrypt(C, K))
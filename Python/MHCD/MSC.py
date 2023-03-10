#monoalphabetic substitution cipher (ma hoa chu don)

def MSC_encrypt(M, K):
    return ''.join(K[ord(c) - 65] for c in M)

def MSC_decrypt(C, K):
    return ''.join(chr(K.find(c) + 65) for c in C)

M = "LIKEFATHERLIKESO"
K = "LYFGMKNERXJPQIVATOHSZDBUCW"
C = MSC_encrypt(M, K)
print(f"C = {C}")
print(f"M = {MSC_decrypt(C, K)}")
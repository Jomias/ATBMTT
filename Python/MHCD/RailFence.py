def rail_fence_encrypt(M, K):
    return "".join(M[j] for i in range(K) for j in range(i, len(M), K))

def rail_fence_decrypt(C, K):
    M = [""] * len(C)
    index = 0
    for i in range(K):
        for j in range(i, len(C), K):
            M[j] = C[index]
            index += 1
    return "".join(M)

M = "WHENINROMEDOASTHER"
K = 4
C = rail_fence_encrypt(M, K)
print("C =", C)
print("M =", rail_fence_decrypt(C, K))
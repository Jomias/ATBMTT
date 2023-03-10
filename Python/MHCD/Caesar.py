def caesar_cypher(M, K):
    return "".join(chr((ord(c) - 65 + K) % 26 + 65) for c in M)

M = "AWOMANGIVESANDFO"
K = 11
encode = caesar_cypher(M, K)
print(caesar_cypher(M, K))
print(caesar_cypher(encode, 26 - K))
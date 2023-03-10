def remove_duplicate_string(K):
    return ''.join(sorted(set(K), key=K.index))

def play_fair_encrypt(M, K):
    matrix = remove_duplicate_string(K)
    for c in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if c not in matrix:
            matrix += c
            if len(matrix) == 25:
                break
    for i in range(0, len(M), 2):
        if i + 1 == len(M) or M[i] == M[i + 1]:
            M = M[:i + 1] + "X" + M[i + 1:]
    C = ""
    for i in range(0, len(M), 2):
        first_pos = matrix.find(M[i])
        second_pos = matrix.find(M[i + 1])
        first_row, first_col = first_pos // 5, first_pos % 5
        second_row, second_col = second_pos // 5, second_pos % 5
        if first_row == second_row:
            C += matrix[first_row * 5 + (first_col + 1) % 5]
            C += matrix[second_row * 5 + (second_col + 1) % 5]
        elif first_col == second_col:
            C += matrix[(first_row + 1) % 5 * 5 + first_col]
            C += matrix[(second_row + 1) % 5 * 5 + second_col]
        else:
            C += matrix[first_row * 5 + second_col]
            C += matrix[second_row * 5 + first_col]
    return C

M = "SOFARSOGOODSO"
K = "EASTORW"
print(play_fair_encrypt(M, K))
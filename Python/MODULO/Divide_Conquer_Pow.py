def power(a, m, n):
    b = 1
    a %= n
    while m > 0:
        if m & 1:
            b = (b * a) % n
        m >>= 1
        a = (a * a) % n
    return b

a, m, n = 419, 6217, 6217
print("b = {}^{} mod {} = {}".format(a, m, n, power(a, m, n)))
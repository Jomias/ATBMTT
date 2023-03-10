def definition_reverse_modulo(m, b):
    return str(next((i for i in range(1, m) if (b * i) % m == 1), "Can't reverse"))

def extended_euclid(m, b):
    A1, A2, B1, B2 = 0, m, 1, b
    #print(f"{'Q':<7} {'A1':<7} {'A2':<7} {'B1':<7} {'B2':<7}")
    #print(f"{'-':<7} {A1:<7} {A2:<7} {B1:<7} {B2:<7}")
    while B2 not in [0, 1]:
        Q = A2 // B2
        T1, T2 = A1 - Q * B1, A2 - Q * B2
        A1, A2 = B1, B2
        B1, B2 = T1, T2
        #print(f"{Q:<7} {A1:<7} {A2:<7} {B1:<7} {B2:<7}")
    return B1 % m if B2 != 0 else "Can't Reserve"


if __name__ == "__main__":
    # 1759 550
    m = 1759
    b = 550
    ans = extended_euclid(m, b)
    print(f"{b}^(-1) mod {m} = {ans}")

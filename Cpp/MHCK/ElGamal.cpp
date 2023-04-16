#include <bits/stdc++.h>
using namespace std;
#define int long long

int power(int a, int m, int n) {
    int b = 1;
    a %= n;
    while (m > 0) {
        if (m & 1) {
            b = (b * a) % n;
        }
        m >>= 1;
        a = (a * a) % n;
    }
    return b;
}

int ExtendedEuclid(int b, int m) {
    int A1 = 0, A2 = m, B1 = 1, B2 = b;
    while(B2 != 0 && B2 != 1) {
        int Q = A2 / B2;
        int T1 = A1 - Q * B1, T2 = A2 - Q * B2;
        A1 = B1, A2 = B2;
        B1 = T1, B2 = T2;
    }
    if (B2 == 0) {
        return -1;
    }
    return ((B1 % m) + m) % m;
}

main() {
    int q = 7919, a = 7, xA = 323, k = 223, M = 364;
    
    // Khóa công khai của An
    int yA = power(a, xA, q);
    cout << "Khoa cong khai cua An: " << endl;
    cout << "yA = a^(xA) mod q = " << a << "^" << xA << " mod " << q << " = " << yA << endl;
    cout << "PU = {q, a, yA} = {" << q << ", " << a << ", " << yA << "}" << endl;  
    cout << endl;

    // (C1, C2) = ?
    int K = power(yA, k, q);
    int C1 = power(a, k, q);
    int C2 = (K * M) % q; 
    cout << "Ban ma (C1, C2): " << endl;
    cout << "K = (yA)^k mod q = " << yA << "^" << k << " mod " << q << " = " << K << endl;
    cout << "C1 = a^k mod q = " << a << "^" << k << " mod " << q << " = "  << C1 << endl;
    cout << "C2 = KM mod q = (" << K << " * " << M << ") mod " << q << " = " << C2 << endl;  
    cout << "(C1, C2) = (" << C1 << ", " << C2 << ")" << endl;
    cout << endl;

    // An giải mã C: M' = ?
    K = power(C1, xA, q);
    int M_2 = (C2 * ExtendedEuclid(K, q)) % q;
    cout << "Cach A giai ma C, M': " << endl;
    cout << "K = (C1)^(xA) mod q = " << C1 << "^" << xA << " mod " << q << " = " << K << endl;;
    cout << "M' = (C2 * K^(-1)) mod q = [(C2 mod q) * (K^(-1) mod q)] mod q = " << M_2 << endl;

    return 0;

}

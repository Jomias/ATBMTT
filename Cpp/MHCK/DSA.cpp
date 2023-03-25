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

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    return n > 1 ? res - res / n : res;
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
    int p = 31, q = 5, h = 23, xA = 3, k = 6, HM = 9;

    // Khoa cong khai cua An yA = ?
    int g = power(h, (p - 1) / q, p);
    int yA = power(g, xA, p);
    cout << "Khoa cong khai cua An: " << endl;
    cout << "g = h^[(p-1)/q] mod p = " << h << "^[(" << p << "-1)/" << q << ")] mod " << p << " = " << g << endl;
    cout << "yA = g^(xA) mod p = " << g << "^" << xA << " mod " << p << " = " << yA << endl;
    cout << endl;

    //Chu ky so cua A cho ban tin M (r, s) = ?
    int r = power(g, k, p) % q;
    int s = (ExtendedEuclid(k, q) * (HM + xA * r)) % q;
    cout << "Chu ky so cua A cho ban tin M (r, s): " << endl;
    cout << "r = (g^k mod p) mod q = (" << g << "^" << k << " mod " << p <<  ") mod " << q << " = " << r << endl;
    cout << "s = [k^(-1) * (H(M) + xA * r)] mod q = " << "[" << k << "^(-1) * (" << HM << " + " << xA << " * " << r << ")] mod " << q << " = " << s << endl;
    cout << "Chu ky so = (r, s) = (" << r << ", " << s << ")" << endl; 
    cout << endl;


    //Xac minh chu ky so:
    int w = ExtendedEuclid(s, q);
    int u1 = (HM * w) % q;
    int u2 = (r * w) % q;
    int v = (power(g, u1, p) * power(yA, u2, p)) % p % q;
    cout << "Xac minh chu ky so: " << endl;
    cout << "w = s^(-1) mod q = " << s << "^(-1) mod " << q << " = " << w << endl; 
    cout << "u1 = (H(M) * w) mod q = (" << HM << " * " << w << ") mod " << q << " = " << u1 << endl;
    cout << "u2 = (r * w) mod q = (" << r << " * " << w << ") mod " << q << " = " << u2 << endl;
    cout << "v = [(g^u1 * yA^u2) mod p] mod q = [(" << g << "^" << u1 << " * " << yA << "^" << u2 << ") mod " << p << "] mod " << q << " = " << v << endl;

    if (v == s) {
        cout << "v = s = " << v << endl;
        cout << "Chu ky dung !";
    } else {
        cout << "v != s" << endl << "Sai !"; 
    }


    return 0;
}
 
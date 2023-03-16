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

int ExtendedEuclid(int m, int b) {
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

int A1(int a, int b, int x, int y, int n) {
    // (a^x + b^y) mod n;
    return (power(a, x, n) + power(b, y, n)) % n;
}

int A2(int a, int b, int x, int y, int n) {
    // (a^x - b^y) mod n;
    return ((power(a, x, n) - power(b, y, n)) % n + n) % n;
}

int A3(int a, int b, int x, int y, int n) {
    // (a^x * b^y) mod n;
    return (power(a, x, n) * power(b, y, n)) % n;
}
int A4(int b, int y, int n) {
    // (b^y)^-1 mod n;
    return ExtendedEuclid(n, power(b, y, n));
}
int A5(int a, int b, int x, int y, int n) {
    // (a^x / b^y) mod n
    return (power(a, x, n) * A4(b, y, n)) % n;
}

main() {
    int a = 71, b = 11, x = 419, y = 369, n = 181;
    cout << "A1 = " << A1(a, b, x, y, n) << endl;
    cout << "A2 = " << A2(a, b, x, y, n) << endl;
    cout << "A3 = " << A3(a, b, x, y, n) << endl;
    cout << "A4 = " << A4(b, y, n) << endl;
    cout << "A5 = " << A5(a, b, x, y, n) << endl;
    return 0;
}

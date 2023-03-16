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

int fermat_pow(int a, int m, int n) {
    if (__gcd(a, n) != 1) {
        return power(a, m, n);
    }
    return power(a, m % (n - 1), n);
}
main() {
    int a = 4, m = 13, n = 13;
    cout << "b = " <<  a << "^" << m << " mod " << n << " = " << fermat_pow(a, m, n);
}
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

int euler_pow(int a, int m, int n) {
    if (__gcd(a, n) == 1) {
        return power(a, m % phi(n), n);
    }
    int temp = phi(n) + 1;
    return power(a, m / temp + m % temp, n);
}
main() {
    int a = 23, m = 3885, n = 395;
    cout << "b = " <<  a << "^" << m << " mod " << n << " = " << euler_pow(a, m, n);
}
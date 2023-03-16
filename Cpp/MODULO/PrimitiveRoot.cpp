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
    for (int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    return n > 1 ? res - res / n : res;
}

bool isPrimitiveRoot(int a, int n) {
    if (__gcd(a, n) != 1) {
        return 0;
    }
    int phi_n = phi(n);
    set <int> factor;
    for (int i = 2; i * i < phi_n; ++i) {
        if (phi_n % i == 0) {
            factor.insert(i);
            if (phi_n / i != i) {
                factor.insert(phi_n / i);
            }
        }
    }
    for (auto x : factor) {
        int temp = power(a, x, n);
        //cout << a << "^" << x << " % " << n << " = " << temp << endl;
        if (power(a, x, n) == 1) {
            return 0;
        }
    }
    return 1;
}
main() {
    int a = 11, n = 331;
    cout << isPrimitiveRoot(a, n);
    return 0;
}
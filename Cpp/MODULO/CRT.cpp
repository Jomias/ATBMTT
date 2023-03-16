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

vector<int> factorize (int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int p = 1;
            while (n % i == 0) {
                p *= i;
                n /= i;
            }
            res.push_back(p);
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}

int pow_CRT(int a, int k, int n) {
    vector <int> m;
    int res = 0;

    //1. Factorize n
    m = factorize(n);

    for (int i = 0; i < m.size(); ++i) {
        //2. Calculate a mod m[i] => power(a, k, m[i]), M[i] = M / m[i]
        //3. Calculate M[i]^-1 mod m[i] => ExtendedEuclid(m[i], M / m[i])
        //4. Calculate each c[i] = M[i] x (M[i]^-1 mod m[i]), a[i] = A mod m[i], item = a[i] * c[i]
        int Mi = n / m[i];
        res += power(a, k, m[i]) * Mi * ExtendedEuclid(m[i], Mi);
    }
    return res % n;
}

main() {
    int a = 199, k = 54, n = 43381;
    cout << "b = " << a << "^" << k << " mod " << n << " = " << pow_CRT(a, k, n);
}
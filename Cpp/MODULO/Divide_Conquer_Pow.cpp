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

main() {
    int a = 419, m = 6217, n = 6217;
    cout << "b = " <<  a << "^" << m << " mod " << n << " = " << power(a, m, n);
    return 0;
}
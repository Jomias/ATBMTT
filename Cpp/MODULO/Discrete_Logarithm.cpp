#include <bits/stdc++.h>
using namespace std;
#define int long long

int Discrete_Logarithm(int a, int b, int n) {
    unordered_map<int, bool> m;
    int base = 1;
    for (int k = 1; k < n; ++k) {
        base = (base * a) % n; 
        //cout << a << "^" << k << " mod " << n << " = " << base << endl;
        if (base == b) return k;
        if (m.find(base) != m.end())    return -1;
        m[base] = 1;
    }
    return -1;
}

main() {
    int a = 3, b = 4, n = 13;
    int kq = Discrete_Logarithm(a % n, b, n);
    cout << "k = log" << a % n << "(" << b << ") mod " << n << " = " << kq;
}
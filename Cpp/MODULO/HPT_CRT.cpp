#include <bits/stdc++.h>
using namespace std;
#define int long long

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

int HPT_CRT(vector<int> m, vector<int> a) {
    int x = 0, M = 1;
    for (int i = 0; i < m.size(); ++i) {
        M *= m[i];
    }
    for (int i = 0; i < m.size(); ++i) {
        int Mi = M / m[i];
        x += a[i] * Mi * ExtendedEuclid(m[i], Mi);
    }
    return x % M;
}

main() {
    vector<int> m = { 13, 17, 19 };
    vector<int> a = { 6, 8, 14 };
    cout << "x = " << HPT_CRT(m, a);
}
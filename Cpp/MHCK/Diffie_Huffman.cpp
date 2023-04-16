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

int cal_y(int a, int x, int q) {
    return power(a, x, q);
}

int cal_K(int y, int x, int q) {
    return power(y, x, q);
}

main() {
    int q = 7879, a = 3, k = 3, xA = 524, xB = 214, K;

    // ý a 1 tìm yA = a^(xA) mod q, khóa phiên K = yA^(xB) mod q 
    int yA = cal_y(a, xA, q);
    cout << "yA = " << a << "^(" << xA << ") mod " << q << " = " << yA << endl;
    K = cal_K(yA, xB, q);
    cout << "Khoa phien K = yA^(xB) mod q = " << yA << "^(" << xB << ") mod " << q << " = " << K << endl;


    // ý b tìm yB = a^(xB) mod q, khóa phiên K = yB^(xA) mod q
    int yB = cal_y(a, xB, q);
    cout << "yB = " << a << "^(" << xB << ") mod " << q << " = " << yB << endl;
    K = cal_K(yB, xA, q);
    cout << "Khoa phien K = yB^(xA) mod q = " << yB << "^(" << xA << ") mod " << q << " = " << K << endl;

    return 0;
}

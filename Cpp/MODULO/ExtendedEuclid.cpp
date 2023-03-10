#include <bits/stdc++.h>
using namespace std;

string DefinitionReverseModulo(int m, int b) {
    for (int i = 1; i < m; ++i) {
        if ((b * i) % m == 1) {
            return to_string(i);
        }
    }
    return "Can't reverse";
}

string ExtendedEuclid(int m, int b) {
    int A1 = 0, A2 = m, B1 = 1, B2 = b;
    //cout << setw(7) << "Q" << setw(7) << "A1" << setw(7) << "A2" << setw(7) << "B1" << setw(7) << "B2" << endl;
    //cout << setw(7) << "-" << setw(7) << A1 << setw(7) << A2 << setw(7) << B1 << setw(7) << B2 << endl;
    while(B2 != 0 && B2 != 1) {
        int Q = A2 / B2;
        int T1 = A1 - Q * B1, T2 = A2 - Q * B2;
        A1 = B1, A2 = B2;
        B1 = T1, B2 = T2;
        //cout << setw(7) << Q << setw(7) << A1 << setw(7) << A2 << setw(7) << B1 << setw(7) << B2 << endl;
    }
    if (B2 == 0) {
        return "Can't reverse";
    }
    return to_string(((B1 % m) + m) % m);
}

int main() {
    int m = 1759;
    int b = 550;
    string ans = DefinitionReverseModulo(m, b);
    cout << "Answer: " << b << "^(-1) mod " << m << " = " <<  ans << endl;
    return 0;
}
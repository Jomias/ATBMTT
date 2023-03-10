//monoalphabetic substitution cipher (ma hoa chu don)

#include <bits/stdc++.h>
using namespace std;

string MSC_encrypt(string M, string K) {
    string C = "";
    for (auto &c : M) {
        C += K[c - 65];
    }
    return C;
}

string MSC_decrypt(string C, string K) {
    string M = "";
    for (auto &c : C) {
        M += K.find(c) + 65;
    }
    return M;
}

int main() {
    string M = "LIKEFATHERLIKESO";
    string K = "LYFGMKNERXJPQIVATOHSZDBUCW";
    string C = MSC_encrypt(M, K);
    cout << "C = " << C << "\n";
    cout << "M = " << MSC_decrypt(C, K);
    return 0;
}
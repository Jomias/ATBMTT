#include <bits/stdc++.h>
using namespace std;

string vigenere_encrypt(string M, string K) {
    string C = "";
    for (int i = 0; i < M.size(); ++i) {
        C += (M[i] + K[i] - 130) % 26 + 65;
    }
    return C;
}

string vigenere_decrypt(string C, string K) {
    string M = "";
    for (int i = 0; i < C.size(); ++i) {
        M += (C[i] - K[i] + 26) % 26 + 65;
    }
    return M;
}

int main() {
    string M = "HONESTYISTHEBE";
    string K = "ABADBE";
    K = K + M.substr(0, M.size() - K.size());
    string C = vigenere_encrypt(M, K);
    cout << "C = " << C << endl;
    cout << "M = " << vigenere_decrypt(C, K);
    return 0;
}
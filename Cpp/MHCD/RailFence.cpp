#include <bits/stdc++.h>
using namespace std;

string rail_fence_encrypt(string M, int K) {
    string C = "";
    for (int i = 0; i < K; ++i) {
        //  j is the position in M that also in row i: i, i + k, i + 2k
        for (int j = i; j < M.size(); j += K) {
            C += M[j];
        }
    }
    return C;
}

string rail_fence_decrypt(string C, int K) {
    string M(C.size(), ' ');
    int index = 0;
    for (int i = 0; i < K; ++i) {
        for (int j = i; j < C.size(); j += K) {
            M[j] = C[index++];
        }
    }
    return M;
}
int main() {
    string M = "WHENINROMEDOASTHER";
    int K = 4;
    string C = rail_fence_encrypt(M, K);
    cout << "C = " << C << endl;
    cout << "M = " << rail_fence_decrypt(C, K);
    return 0;
}
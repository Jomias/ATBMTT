#include <bits/stdc++.h>
using namespace std;

string rail_fence_encrypt(string M, int K) {
    string C = "";
    int count = 0, col_num = (M.size() + K - 2) / (K - 1);
    vector<vector<char>> rails(K, vector<char>(col_num, '.'));
    for (int j = 0; j < col_num && count < M.size(); ++j) {
        int start = (j & 1) ? K - 1 : 0;
        int end = (j & 1) ? 0 : K - 1;
        int step = (j & 1) ? -1 : 1;
        for (int i = start; i != end && count < M.size(); i += step) {
            rails[i][j] = M[count++];
        }
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < col_num; ++j) {
            //cout << rails[i][j] << " ";
            if(rails[i][j] != '.') {
                C += rails[i][j];
            }
        }
        //cout << endl;
    }
    return C;
}


string rail_fence_decrypt(string C, int K) {
    string M = "";
    int count = 0, col_num = (C.size() + K - 2) / (K - 1);
    vector<vector<char>> rails(K, vector<char>(col_num, '.'));
    for (int i = 0; i < K && count < C.size(); ++i) {
        for (int j = 0; j < col_num && count < C.size(); ++j) {
            if (j & 1 && i == 0)    continue;
            if ((j % 2 == 0) && (i == K - 1))   continue;
            if (j == col_num - 1) {
                int temp = j & 1 ? K - i : i + 1;
                if (j * (K - 1) + temp > C.size())   continue;
            }
            rails[i][j] = C[count++];
        }
    }
    count = 0;
    for (int j = 0; j < col_num && count < C.size(); ++j) {
        int start = (j & 1) ? K - 1 : 0;
        int end = (j & 1) ? 0 : K - 1;
        int step = (j & 1) ? -1 : 1;
        for (int i = start; i != end && count < C.size(); i += step) {
            M += rails[i][j];
            count++;
        }
    }
    return M;
}

main() {
    string M = "WHENINROMEDOASTHER";
    int K = 4;
    string C = rail_fence_encrypt(M, K);
    cout << "C = " << C << endl;
    cout << "M = " << rail_fence_decrypt(C, K);
    return 0;   
}
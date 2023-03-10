#include <bits/stdc++.h>
using namespace std;

string remove_duplicate_string(string K) {
    unordered_map <char, bool> m;
    string ans = "";    
    for (int i = 0; i < K.size(); ++i) {
        if (m.find(K[i]) == m.end()) {
            ans += K[i];
            m[K[i]] = 1;
        } 
    }
    return ans;
}
string play_fair_encrypt(string M, string K) {
    string matrix = remove_duplicate_string(K);
    for (char c = 'A'; c <= 'Z' && matrix.size() <= 25; ++c) {
        if (c != 'J' && matrix.find(c) == string::npos) {
            matrix += c;
        }
    }
    for (int i = 0; i < M.size(); i += 2) {
        if (i + 1 == M.size() || M[i] == M[i + 1]) {
            M.insert(i + 1, "X");
        }
    }
    string C = "";
    for (int i = 0; i < M.size(); i += 2) {
        int firstPos = matrix.find(M[i]), secondPos = matrix.find(M[i + 1]);
        int firstRow = firstPos / 5, firstCol = firstPos % 5; 
        int secondRow = secondPos / 5, secondCol = secondPos % 5;

        if (firstRow == secondRow) {
            C += matrix[firstRow * 5 + (firstCol + 1) % 5];
            C += matrix[secondRow * 5 + (secondCol + 1) % 5];
        } else if (firstCol == secondCol) {
            C += matrix[(firstRow + 1) % 5 * 5 + firstCol];
            C += matrix[(secondRow + 1) % 5 * 5 + secondCol];
        } else {
            C += matrix[firstRow * 5 + secondCol];
            C += matrix[secondRow * 5 + firstCol];
        }
    }
    return C;
}

int main() {
    string M = "SOFARSOGOODSO";
    string K = "EASTORW";
    cout << play_fair_encrypt(M, K);
    return 0;
}
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
string play_fair_encrypt(string M, string K, vector<int> &xPos) {
    string matrix = remove_duplicate_string(K);
    for (char c = 'A'; c <= 'Z' && matrix.size() <= 25; ++c) {
        if (c != 'J' && matrix.find(c) == string::npos) {
            matrix += c;
        }
    }
    for (int i = 0; i < M.size(); i += 2) {
        if (i + 1 == M.size() || M[i] == M[i + 1]) {
            M.insert(i + 1, "X");
            xPos.push_back(i + 1);
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

string play_fair_decrypt(string C, string K, vector<int> xPos) {
    string matrix = remove_duplicate_string(K);
    for (char c = 'A'; c <= 'Z' && matrix.size() <= 25; ++c) {
        if (c != 'J' && matrix.find(c) == string::npos) {
            matrix += c;
        }
    }
    string M = "";
    for (int i = 0; i < C.size(); i += 2) {
        int firstPos = matrix.find(C[i]), secondPos = matrix.find(C[i + 1]);
        int firstRow = firstPos / 5, firstCol = firstPos % 5; 
        int secondRow = secondPos / 5, secondCol = secondPos % 5;

        if (firstRow == secondRow) {
            M += matrix[firstRow * 5 + (firstCol + 4) % 5];
            M += matrix[secondRow * 5 + (secondCol + 4) % 5];
        } else if (firstCol == secondCol) {
            M += matrix[(firstRow + 4) % 5 * 5 + firstCol];
            M += matrix[(secondRow + 4) % 5 * 5 + secondCol];
        } else {
            M += matrix[firstRow * 5 + secondCol];
            M += matrix[secondRow * 5 + firstCol];
        }
    }
    for (int i = xPos.size() - 1; i >= 0; --i) {
        M.erase(xPos[i], 1);
    }
    return M;
}

int main() {
    vector <int> xPos;
    string M = "SOFARSOGOODSO";
    string K = "EASTORW";
    string C = play_fair_encrypt(M, K, xPos);

    cout << "C = " << C << endl;
    cout << "M = " << play_fair_decrypt(C, K, xPos);
    return 0;
}
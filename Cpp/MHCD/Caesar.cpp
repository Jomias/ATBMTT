#include <bits/stdc++.h>
using namespace std;

string caesar_cypher(string M, int K) {
    string C = "";
    for (auto c : M) {
        C += (c - 65 + K) % 26 + 65;
    }
    return C;
}

// (decode thì lấy cypher cho 26 - K)

int main() {
    string M = "AWOMANGIVESANDFO";
    int K = 11;
    cout << caesar_cypher(M, K) << endl;
    cout << caesar_cypher(caesar_cypher(M, K), 26 - K);
}
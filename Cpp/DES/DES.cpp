#include <bits/stdc++.h>
#include "Main_Func.h"
using namespace std;
#define int long long

unsigned int DES_ENCRYPT(unsigned int x, unsigned int k) {
    unsigned int L0, R0, L1, R1, XR1K, SXR1K, FP;
    unsigned int Ks[16];   
    Gen_Key(k, Ks);
    unsigned int y = IP(x);
    SPLIT(y, L0, R0);
    for (int i = 0; i < 16; ++i) {
        FP = F(R0, Ks[i]);
        R1 = FP ^ L0, L1 = R0;
        R0 = R1, L0 = L1;
        //cout << setw(10) <<"L[" << dec << i + 1 << "] = " << uppercase<< hex << L1 << " " << setw(10) << dec << "R[" << i + 1 << "] = " << hex << R1 << endl;
    }

    return IP_REVERSE((R1 << 32) | L1);
}

unsigned int DES_DECRYPT(unsigned int C, unsigned int k) {
    unsigned int L0, R0, L1, R1, XR1K, SXR1K, FP;
    unsigned int Ks[16];   
    Gen_Key(k, Ks);
    unsigned int y = IP(C);
    SPLIT(y, L0, R0);
    for (int i = 0; i < 16; ++i) {
        FP = F(R0, Ks[15-i]);
        R1 = FP ^ L0, L1 = R0;
        R0 = R1, L0 = L1;
        //cout << setw(10) <<"L[" << dec << i + 1 << "] = " << uppercase<< hex << L1 << " " << setw(10) << dec << "R[" << i + 1 << "] = " << hex << R1 << endl;
    }
    return IP_REVERSE((R1 << 32) | L1);
}
main() {
    unsigned int K = 0x17FFCC5ADBF3EA87;
    unsigned int M = 0xE36B4C92DE9AD726;
    unsigned int C = DES_ENCRYPT(M, K);
    M = DES_DECRYPT(C, K);
    cout << "C = " << uppercase << hex << C << endl;
    cout << "M = " << uppercase << hex << M << endl;
    
    return 0;

}
 
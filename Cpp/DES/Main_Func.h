
#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H
#define int long long
#include "Gen_Key.h"
#define int long long

unsigned int IP(unsigned int x) {
    unsigned int y = 0;
    for (int i = 0; i < 64; ++i) {
        unsigned int val = (x >> (64 - ip[i])) & 1;
        y |= (val << (63 - i));
    }
    return y;
}
void SPLIT(unsigned int x, unsigned int &L, unsigned int &R) {
    L = x >> 32;
    R = x & 0xFFFFFFFF;
}

unsigned int E(unsigned int R) {
    unsigned int R1 = 0;
    for (int i = 0; i < 48; ++i) {
        int val = (R >> (32 - e[i])) & 1;
        R1 |= (val << (47 - i));
    }
    return R1;
}

unsigned int XOR(unsigned int R1, unsigned int Ks) {
    return R1 ^ Ks;
}

unsigned int SUB(unsigned int XR1K) {
    // 8 6bit
    int chunks[8];
    for (int i = 0; i < 8; i++) {
        chunks[i] = (XR1K >> (6 * (7 - i))) & 0x3F;
    }

    unsigned int SXR1K = 0;
    for (int i = 0; i < 8; i++) {
        unsigned int row = ((chunks[i] & 0x20) >> 4) | (chunks[i] & 1);
        unsigned int col = (chunks[i] >> 1) & 0xF;
        unsigned int val = S_boxes[i][row][col];
        SXR1K |= val << (4 * (7 - i));
    }
    return SXR1K;
}

unsigned int P(unsigned int SXR1K) {
    unsigned int F = 0;
    for (int i = 0; i < 32; i++) {
        unsigned int val = (SXR1K >> (32 - p[i])) & 1;
        F |= (val << (31 - i));
    }
    return F;
}

unsigned int F(unsigned int R, unsigned int Ks) {
    unsigned int R1, XR1K, SXR1K, f;
    R1 = E(R);
    XR1K = XOR(R1, Ks);
    SXR1K = SUB(XR1K);
    f = P(SXR1K);
    return f;
}

unsigned int IP_REVERSE(unsigned int M) {
    unsigned int res = 0;
    for (int i = 0; i < 64; ++i) {
        unsigned int val = (M >> (64 - ip_reverse[i])) & 1;
        res |= (val << (63 - i));
    }
    return res;
}
#endif
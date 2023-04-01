
#ifndef GEN_KEY_H
#define GEN_KEY_H
#include "Des.h"
#include "Helper.h"

unsigned int PC1(unsigned int K) {
    unsigned int K1 = 0;
    for (int i = 0; i < 56; ++i) {
        unsigned int val = (K >> (64 - pc1[i])) & 1;  // Lay gia tri cua bit
        K1 |= (val << (55 - i));  // Set bit theo vi tri
    }
    return K1;
}

void SPLIT_KEY(unsigned int K1, unsigned int &C, unsigned int &D) {
    C = K1 >> 28;   // nua trai 28 bit
    D = K1 & 0xFFFFFFF; // lay nua phai 28 bit
}

void ShiftLeft(unsigned int &x, int s) {
    unsigned int temp = x;
    x = (temp << s & 0xFFFFFFF) | (temp >> (28 - s)) ;
}

unsigned int PC2(unsigned int &C, unsigned int &D, int s) {
    ShiftLeft(C, s);    ShiftLeft(D, s);
    unsigned int Ks = 0, val, bit;
    for (int i = 0, index; i < 48; ++i) {
        index = pc2[i] > 28 ? pc2[i] - 28 : pc2[i];
        bit = GetBit28(pc2[i] > 28 ? D : C, index);
        Ks = (Ks << 1) | bit;
    }
    return Ks;
}

void Gen_Key(unsigned int K, unsigned int Ks[16]) {
    unsigned int C_temp, D_temp;
    unsigned int K1 = PC1(K);
    SPLIT_KEY(K1, C_temp, D_temp);
    for (int i = 0; i < 16; ++i) {
        Ks[i] = PC2(C_temp, D_temp, s[i]);
    }
}
#endif
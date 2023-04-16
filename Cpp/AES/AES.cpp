#include <bits/stdc++.h>
using namespace std;
#include "AES.h"
#include "Helper.h"


void SubBytes(uint8_t state[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            state[i][j] = SBox[state[i][j]];
        }
    }
}
void InvSubBytes(uint8_t state[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            state[i][j] = InvS[state[i][j]];
        }
    }
}
void ShiftRows(uint8_t state[4][4])
{
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            uint8_t tmp = state[i][0];
            for (int k = 0; k < 3; k++)
            {
                state[i][k] = state[i][k + 1];
            }
            state[i][3] = tmp;
        }
    }
}
void InvShiftRows(uint8_t state[4][4])
{
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            uint8_t tmp = state[i][3];
            for (int k = 3; k > 0; k--)
            {
                state[i][k] = state[i][k - 1];
            }
            state[i][0] = tmp;
        }
    }
}
void InvMixColumns(uint8_t state[4][4])
{
    uint8_t* tmp = new uint8_t[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp[j] = state[j][i];
        }
        for (int j = 0; j < 4; j++)
        {
            state[j][i] = GF8Mul(InvMixTable[j][0], tmp[0]) ^ GF8Mul(InvMixTable[j][1], tmp[1]) ^ GF8Mul(InvMixTable[j][2], tmp[2]) ^ GF8Mul(InvMixTable[j][3], tmp[3]);
        }
    }
    delete[] tmp;
}
void MixColumns(uint8_t state[4][4])
{
    uint8_t* tmp = new uint8_t[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; ++j) 
        {
            tmp[j] = state[j][i];
        }
        for (int j = 0; j < 4; j++)
        {
            state[j][i] = 0;
            for (int k = 0; k < 4; k++)
            {
                state[j][i] ^= GF8Mul(mixTable[j][k], tmp[k]);
            }
        }
    }
}
void AddRoundKey(uint8_t state[4][4], const uint8_t key[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            state[i][j] ^= key[i][j];
        }
    }
}
uint8_t* KeyExpansion(const uint8_t* K) {
    uint8_t* Kp = new uint8_t[176];
    memcpy(Kp, K, 16);
    for (int i = 16; i < 176; i += 4) {
        uint8_t temp[4];
        memcpy(temp, Kp + i - 4, 4);
        if (i % 16 == 0) {
            uint8_t t = temp[0];
            temp[0] = SBox[temp[1]] ^ RCon[i / 16 - 1];
            temp[1] = SBox[temp[2]];
            temp[2] = SBox[temp[3]];
            temp[3] = SBox[t];
        }
        for (int j = 0; j < 4; ++j) {
            Kp[i + j] = Kp[i + j - 16] ^ temp[j];
        }
    }
    return Kp;
}

uint8_t* aes_encrypt(const uint8_t *x, const uint8_t *k) {
    uint8_t state[4][4];
    BytesToState(x, state);
    uint8_t* out = new uint8_t[16];
    uint8_t* expandedKey = KeyExpansion(k);
    uint8_t (*round0)[4] = (uint8_t (*)[4]) (expandedKey);
    ReverseMatrix(round0);
    AddRoundKey(state, round0);
    for (int i = 1; i <= 10; i++) {
        SubBytes(state);
        ShiftRows(state);
        if (i != 10) {
            MixColumns(state);
        }
        uint8_t (*roundKey)[4] = (uint8_t (*)[4]) (expandedKey + i * 16);
        ReverseMatrix(roundKey);
        AddRoundKey(state, roundKey);
    }

    StateToBytes(state, out);
    return out;
}

uint8_t* aes_decrypt(const uint8_t* C, const uint8_t* k) {
    uint8_t state[4][4];
    BytesToState(C, state);

    uint8_t* out = new uint8_t[16];
    uint8_t* expandedKey = KeyExpansion(k);
    uint8_t (*round10)[4] = (uint8_t (*)[4]) (expandedKey + 160);
    ReverseMatrix(round10);
    AddRoundKey(state, round10);

    for (int i = 9; i >= 0; --i) {
        InvShiftRows(state);
        InvSubBytes(state);
        uint8_t (*roundKey)[4] = (uint8_t (*)[4]) (expandedKey + i * 16);
        ReverseMatrix(roundKey);
        AddRoundKey(state, roundKey);
        if (i == 0) {
            break;
        }
        InvMixColumns(state);   
    }


    StateToBytes(state, out);
    return out;
}

main() {
    // K = 2b7e151628aed2a6abf7158809cf4f3c
    // M = 3243f6a8885a308d313198a2e0370734
    uint8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t x[16] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    uint8_t* output_encrypt = aes_encrypt(x, key);
    showMatrix(output_encrypt); cout << endl;
    uint8_t* output_decrypt = aes_decrypt(output_encrypt, key);
    showWord(output_decrypt); cout << endl;

    return 0;
}
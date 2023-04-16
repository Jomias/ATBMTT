
#ifndef HELPER_H
#define HELPER_H

void ReverseMatrix(uint8_t arr[][4]) {
    uint8_t temp;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}
void BytesToState(const uint8_t* x, uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[j][i] = x[i * 4 + j];
        }
    }
}
uint8_t GF8Mul(uint8_t a, uint8_t b)
{
    uint8_t p = 0;
    uint8_t hi_bit_set;
    for (int i = 0; i < 8; i++)
    {
        if (b & 1)  p ^= a;
        hi_bit_set = a & 0x80;
        a <<= 1;
        if (hi_bit_set) a ^= 0x1B;
        b >>= 1;
    }
    return p;
}

void showWord(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << uppercase << setfill('0') << setw(2) << static_cast<int>(state[j][i]);
        }
    }
}
void showWord(uint8_t state[16]) {
    for (int i = 0; i < 16; i++) {
        cout << hex << uppercase << setfill('0') << setw(2) << static_cast<int>(state[i]);
    }
}

void showMatrix(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << uppercase << setfill('0') << setw(2) << static_cast<int>(state[i][j]) << " ";
        }
        cout << endl;
    }
}

void showMatrix(const uint8_t state[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << uppercase << setfill('0') << setw(2) << static_cast<int>(state[i + 4*j]) << " ";
        }
        cout << endl;
    }
}
void StateToBytes(const uint8_t state[4][4], uint8_t* out) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out[i * 4 + j] = state[j][i];
        }
    }
}
#endif
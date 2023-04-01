
#ifndef HELPER_H
#define HELPER_H
#define int long long

unsigned int GetBit32(unsigned K, int i) {
    return K >> (32 - i) & 1;
}
unsigned int GetBit28(unsigned K, int i) {
    return K >> (28 - i) & 1;
}
void ShowByte(unsigned int C)
{
	for(int i = 1; i <= 16; i++)
	{
		unsigned int b = (C >> (64 - 4*i)) & 0xF;
		printf("%X", b);
	}
}

#endif
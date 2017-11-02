#include "base.h"

void *memset(void *dst, int value, uint count) {
    uchar* p=dst;
    while (count--)
        *p++ = (uchar) value;
    return dst;
}

void *memcpy(void *dst, void *src, uint count) {
    uchar *dp = dst;
    const uchar *sp = src;
    while (count--)
        *dp++ = *sp++;
    return dst;
}

int strncmp(const char *p, const char *q, uint n) {
    while (n--)
        if (*p++ != *q++)
            return *(uchar*)(p - 1) - *(uchar*)(q - 1);
    return 0;
}

static void negate_and_revert(int x, char* str, int i) {
	if (x < 0) {
		str[i] = '-';
	} else {
		i--;
	}
	//reversing
	for (int j = 0; j < i; j++, i--) {
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

void itoa (int x, char* str) {
	int temp = x;
	if (x < 0) {
		temp = -x;
	}
	int i = 0;
	while (temp != 0) {
		str[i] = '0' + temp % 10;
		temp = temp / 10;
		i++;
	}
	negate_and_revert(x, str, i);
}

void itox (int x, char* str) {
	int temp = x;
	if (x < 0) {
		temp = -x;
	}
	int i = 0;
	while (temp != 0) {
		int r = temp % 16;
		if (r > 9) {
			str[i] = 'a' + r % 10;
		} else {
			str[i] = '0' + r;
		}
		temp = temp / 16;
		i++;
	}
	str[i++] = 'x';
	str[i++] = '0';
	negate_and_revert(x, str, i);
}

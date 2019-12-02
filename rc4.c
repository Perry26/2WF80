#include <stdbool.h>
#include <stdio.h>

void rc4(int* k, int l, int* outarray, int outbytes) {
	int S[256];
	for(int i = 0; i < 256; i++) {
		S[i] = i;
	}
	int j = 0;
	for(int i = 0; i < 256; i++) {
		j = ( j + S[i] + k[i%l] ) % 256;
		int temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}

	int i = 0;
	j = 0;
	for (int k = 0; k < outbytes; k++) {
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		int temp = S[i];
		S[i] = S[j];
		S[j] = temp;
		outarray[k] = S[(S[i] + S[j]) % 256];
	}
	return;
}

int compare_array(int* a1, int* a2, int length) {
	for (int i = 0; i < length; i++) {
		if (a1[i] != a2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int key[5];
	key[0] = 80;
	int expected[10] = {130, 189, 254, 192, 238, 132, 216, 132, 82, 173};
	for(int a = 0; a < 256; a++) {
		printf("a: %d\n", a);
		for(int b = 0; b < 256; b++) {
			printf("b: %d\n", b);
			for(int c = 0; c < 256; c++) {
				//printf("c: %d\n", c);
				for(int d = 0; d < 256; d++) {
					key[1] = a;
					key[2] = b;
					key[3] = c;
					key[4] = d;
					int outarray[10];
					rc4(key, 5, outarray, 10);
					/*printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", outarray[0], outarray[1], outarray[2], outarray[3], outarray[4], outarray[5] ,outarray[6] ,outarray[7] ,outarray[8] ,outarray[9]);
					*/
					if (compare_array(outarray, expected, 10)) {
						printf("Yes!: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", outarray[0], outarray[1], outarray[2], outarray[3], outarray[4], outarray[5] ,outarray[6] ,outarray[7] ,outarray[8] ,outarray[9]);
						return 0;
					}
				}
			}
		}
	}
}


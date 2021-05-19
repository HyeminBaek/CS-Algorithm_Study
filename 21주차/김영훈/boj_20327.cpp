#include<iostream>
using namespace std;
int N, R,A[(1<<7)][(1<<7)],sz,k,l,temp[(1<<7)][(1<<7)];


void OpSwap(int r, int c, int l,int k) {
	if (r >= sz) {
		return;
	}	
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			if (k == 1) {
				temp[i][j] = A[r + l - 1 - i][c + j];
			}
			else {
				temp[i][j] = A[r + i][c + l - 1 - j];
			}
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			A[r+i][c+j] = temp[i][j];
		}
	}
	OpSwap(r + ((c + l) / sz) * l, (c + l) % sz,l,k);
}

void OpRotate(int r, int c, int l, int k) {
	if (r >= sz) {
		return;
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			if (k == 1) {
				temp[j][l-1-i] = A[r+i][c+j];
			}
			else {
				temp[l-j-1][i] = A[r+i][c+j];
			}
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			A[r + i][c + j] = temp[i][j];
		}
	}
	OpRotate(r + ((c + l) / sz) * l, (c + l) % sz, l,k);
}
void OpSwap2(int l, int k) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (k == 1) {
				temp[sz - 1 - i][j] = A[i][j];
			}
			else {
				temp[i][sz - 1 - j] = A[i][j];
			}
		}
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			A[i][j] = temp[i][j];
		}
	}
	OpSwap(0, 0, l, k);
	
}
void OpRotate2(int l, int k) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (k == 1) {
				temp[j][sz - 1 - i] = A[i][j];
			}
			else {
				temp[sz - 1 - j][i] = A[i][j];
			}
		}
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			A[i][j] = temp[i][j];
		}
	}
	OpRotate(0, 0, l, 1-k);
}
void Operating(int k, int l) {
	switch (k) {
	case 1:
	case 2:
		OpSwap(0, 0, l, k%2);
		break;
	case 3:
	case 4:
		OpRotate(0, 0, l, k%2);
		break;
	case 5:
	case 6:
		OpSwap2(l, k%2);
		break;
	case 7:
	case 8:
		OpRotate2(l, k%2);
		break;
	}
	
	
}
int main() {
	scanf("%d%d", &N, &R);
	sz = (1 << N);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < R; i++) {
		scanf("%d%d", &k, &l);
		Operating(k, (1<<l));	
	}

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
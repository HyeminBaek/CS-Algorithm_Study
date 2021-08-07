#include<iostream>
#include<string>
using namespace std;
int T, N;
char cube[6][9], color[6] = { 'w','b','r','g','o','y' },*side[6][12],*front[6][8];
string s;
void Init() {
	//À­¸é 0
	for (int i = 0; i < 12; i++) {
		
		side[0][i] = &cube[i / 3+1][2-(i % 3)];
		
	}
	for (int i = 0; i < 8; i++) {
		front[0][i] = &cube[0][i];
	}
	//¾Æ·§¸é 5
	for (int i = 0; i < 12; i++) {
		side[5][i] = &cube[4-i / 3][6-(i % 3)];
	}
	for (int i = 0; i < 8; i++) {
		front[5][i] = &cube[5][i];
	}
	//¿À¸¥ÂÊ 1, ¾Õ 2, ¿ÞÂÊ 3, µÞ¸é 4
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			side[i][j] = &cube[(2 + i) % 4+1][(8-j)%8];
		}
		for (int j = 6; j < 9; j++) {
			side[i][j] = &cube[(i%4)+1][10-j];
		}
		for (int j = 0; j < 8; j++) {
			front[i][j] = &cube[i][j];
		}
	}
	side[1][3] = &cube[5][4];
	side[1][4] = &cube[5][3];
	side[1][5] = &cube[5][2];
	side[1][9] = &cube[0][4];
	side[1][10] = &cube[0][3];
	side[1][11] = &cube[0][2];

	side[2][3] = &cube[5][2];
	side[2][4] = &cube[5][1];
	side[2][5] = &cube[5][0];
	side[2][9] = &cube[0][6];
	side[2][10] = &cube[0][5];
	side[2][11] = &cube[0][4];
	
	
	
	side[3][3] = &cube[5][0];
	side[3][4] = &cube[5][7];
	side[3][5] = &cube[5][6];
	side[3][9] = &cube[0][0];
	side[3][10] = &cube[0][7];
	side[3][11] = &cube[0][6];

	side[4][3] = &cube[5][6];
	side[4][4] = &cube[5][5];
	side[4][5] = &cube[5][4];
	side[4][9] = &cube[0][2];
	side[4][10] = &cube[0][1];
	side[4][11] = &cube[0][0];
}
void Reset() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			cube[i][j] = color[i];
		}
	}
}
void Rotate(char c1, char c2) {
	char temp1[12],temp2[8];
	int target;
	switch (c1) {
	case 'U':
		target = 0;
		break;
	case 'D':
		target = 5;
		break;
	case 'R':
		target = 1;
		break;
	case 'F':
		target = 2;
		break;
	case 'L':
		target = 3;
		break;
	case 'B':
		target = 4;
		break;
	}
	for (int i = 0; i < 12; i++) {
		temp1[i] = *side[target][i];
	}
	for (int i = 0; i < 8; i++) {
		temp2[i] = *front[target][i];
	
	}
	int d = (c2 == '+' ? -1 : 1);
	for (int i = 0; i < 12; i++) {
		*side[target][i] = temp1[(12+i + 3*d) % 12];
	}
	for (int i = 0; i < 8; i++) {
		*front[target][i] = temp2[(8 + i+2*d) % 8];
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	Init();
	while (T--) {
		Reset();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> s;
			Rotate(s[0], s[1]);
		}
		for (int i = 0; i < 3; i++) {
			printf("%c", cube[0][i]);
		}

		printf("\n%c%c%c\n", cube[0][7], 'w', cube[0][3]);
		for (int i = 0; i < 3; i++) {
			printf("%c", cube[0][6-i]);
		}
		printf("\n");

		
	}


	return 0;
}
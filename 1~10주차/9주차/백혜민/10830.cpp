#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N; long long B;
int matrix[5][5], answer[5][5];

void mul(int v1[][5], int v2[][5])
{
	int temp[5][5]; memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				temp[i][j] += (v1[i][k] * v2[k][j]) % 1000;

			temp[i][j] %= 1000;
		}
	}

	memcpy(v1, temp, sizeof(temp));
}
void sol()
{
	answer[0][0] = 1, answer[1][1] = 1, answer[2][2] = 1, answer[3][3] = 1, answer[4][4] = 1; // E 

	while (B > 0)
	{
		if (B % 2 == 1)
			mul(answer, matrix);

		mul(matrix, matrix);
		B /= 2;
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
	}
}
int main()
{
	init();
	sol();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << answer[i][j] << " ";
		cout << "\n";
	}

	return 0;
}

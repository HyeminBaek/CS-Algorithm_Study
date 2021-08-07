#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

/*
1. 궁수는 N+1행에 배치 *3 (열)
2. 거리가 D이하인 적 중 가장 가까운 적 동시 공격
3. 하나의 궁수가 공격할 때 거리 여러 개면 가장 왼쪽 공격(열 작은거)
20:50~

반례1
10 10 8
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
30


*/

struct arch
{
	int ex, ey, dist, col;
};
int N, M, D, answer;
int arr[16][16], tmp[16][16];

void print()
{
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << tmp[i][j] << " ";
		cout << endl;
	}
}
void mov()
{
	for (int i = N; i > 1; i--)
	{
		for (int j = 1;j<=M;j++)
		{
			tmp[i][j] = tmp[i - 1][j];
			if (i == 2) tmp[1][j] = 0;
		}
	}
}
bool chk()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (tmp[i][j]) return true;
		}
	}
	return false;
}
void shoot(int x,int y,int z)
{
	 memcpy(tmp, arr, sizeof(arr));
	int sum = 0;
	
	while (1)
	{
		arch target[3] = { {-1,-1,987654321,x}, {-1,-1,987654321,y} ,{-1,-1,987654321,z} };

		for (int i = N; i >= 1; i--)
		{
			for (int j = 1; j <= M; j++)
			{
				if (!tmp[i][j]) continue;

				for (int k = 0; k < 3; k++)//궁수
				{
					//|r1-r2| + |c1-c2|
					int diff = abs(i - (N + 1)) + abs(j - target[k].col);
					if (diff <= D)
					{
						if (target[k].dist > diff)
						{
							target[k].ex = i, target[k].ey = j;
							target[k].dist = diff;
						}
						else if (target[k].dist == diff)
						{
							if (target[k].ey > j)
							{
								target[k].ex = i; target[k].ey = j;
							}
						}
					}
				}
			}
		}
		
		for (int k = 0; k < 3; k++)
		{
			if (target[k].ex == -1) continue;

			if (tmp[target[k].ex][target[k].ey])
			{
				tmp[target[k].ex][target[k].ey] = 0;
				sum += 1;
			}
		}
		mov();
		if (!chk()) break;
	}

	answer = (answer < sum) ? sum : answer;
}
void combi()
{
	for (int i = 1; i <= M - 2; i++)
	{
		for (int j = i + 1; j <= M - 1; j++)
		{
			for (int k = j + 1; k <= M; k++)
			{
				shoot(i, j, k);
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> D;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
}
int main()
{
	init();
	combi();

	cout << answer;

	return 0;
}

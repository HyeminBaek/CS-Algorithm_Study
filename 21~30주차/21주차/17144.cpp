#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct purify //공기청정기 위치 저장용 구조체
{
	int o; int t;
};
purify p = { 0,0 };
int r, c;
int arr[51][51];//원본 배열

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void spread()
{
	int cp[51][51] = { 0, };//임시 배열

	cp[p.o][0] = -1; cp[p.t][0] = -1;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == -1) continue;

			int dir = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];

				if (0 <= nx && nx < r && 0 <= ny && ny < c)
				{
					if (cp[nx][ny] != -1)
					{
						//미세먼지 확산,네 방향, 확산되는 양은 A/5, 남은 양은 A-(A/5)*dir
						cp[nx][ny] += (int)(arr[i][j] / 5);
						dir++;
					}
				}
			}
			cp[i][j] += arr[i][j] - ((int)(arr[i][j] / 5))*dir;
		}
	}
	memcpy(arr, cp, sizeof(cp));
}
//위는 반시계 아래는 시계
void clock()
{
	int cp[51][51];
	memcpy(cp, arr, sizeof(arr));

	cp[p.o][1] = 0;
	for (int i = 2; i < c; i++)
		cp[p.o][i] = arr[p.o][i - 1];
	for (int i = p.o - 1; i >= 0; i--)
		cp[i][c - 1] = arr[i + 1][c - 1];
	for (int i = c - 2; i >= 0; i--)
		cp[0][i] = arr[0][i + 1];
	for (int i = 1; i < p.o; i++)
		cp[i][0] = arr[i - 1][0];

	cp[p.t][1] = 0;
	for (int i = 2; i < c; i++)
		cp[p.t][i] = arr[p.t][i - 1];
	for (int i = p.t + 1; i < r; i++)
		cp[i][c - 1] = arr[i - 1][c - 1];
	for (int i = c - 2; i >= 0; i--)
		cp[r-1][i] = arr[r-1][i + 1];
	for (int i = r - 2; i > p.t; i--)
		cp[i][0] = arr[i + 1][0];

	memcpy(arr, cp, sizeof(cp));
}
int sum()
{
	int answer = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if(arr[i][j]>0)
				answer += arr[i][j];
		}
	}

	return answer;
}
void print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> r >> c >> T;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)//공기청정기 위치 저장
			{
				if (p.o == 0) p.o = i;
				else p.t = i;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		spread();
		clock();
	}

	cout << sum();

	return 0;
}

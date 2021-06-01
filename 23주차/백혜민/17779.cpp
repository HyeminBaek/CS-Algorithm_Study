#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, answer;
int arr[21][21];

void sol(int x, int y, int d1, int d2)
{
	//x = 3, y = 3, d1 = 1, d2 = 1;
	int temp[21][21] = { 0, };

	vector<int> v;

	//경계선 작업
	for (int i = 0; i <= d1; i++)
	{
		temp[x + i][y - i] = 5;
		temp[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++)
	{
		temp[x + i][y + i] = 5;
		temp[x + d1 + i][y - d1 + i] = 5;
	}
	//경계선 안쪽 작업
	for (int i = x + 1; i < x + d1 + d2; i++)
	{
		bool flag = false;
		for (int j = 1; j <= N; j++)
		{
			if (!flag)
			{
				if (temp[i][j] == 5) flag = true;
			}
			else
			{
				if (temp[i][j] == 5) break;
				temp[i][j] = 5;
			}
		}
	}
	//1번 선거구
	for (int i = 1; i < x + d1; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (temp[i][j] == 5) break;
			temp[i][j] = 1;
		}
	}
	for (int i = 1; i <= x + d2; i++)
	{
		for (int j = y+1; j <= N; j++)
		{
			if (temp[i][j] == 5) continue;
			temp[i][j] = 2;
		}
	}
	for (int i = x+d1; i <= N; i++)
	{
		for (int j = 1; j < y-d1+d2; j++)
		{
			if (temp[i][j] == 5) break;
			temp[i][j] = 3;
		}
	}
	for (int i = x+d2+1; i <= N; i++)
	{
		for (int j = y-d1+d2; j <= N; j++)
		{
			if (temp[i][j] == 5) continue;
			temp[i][j] = 4;
		}
	}
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int o = 0, t = 0, th = 0, f = 0, fv = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			switch (temp[i][j])
			{
			case 1: o += arr[i][j]; break;
			case 2: t += arr[i][j]; break;
			case 3: th += arr[i][j]; break;
			case 4: f += arr[i][j]; break;
			case 5: fv += arr[i][j]; break;
			}
		}
	}

	//cout << o << " " << t << " " << th << " " << f << " " << fv << endl;
	v.push_back(o); v.push_back(t); v.push_back(th); v.push_back(f); v.push_back(fv);
	sort(v.begin(), v.end());
	answer = (answer > v.back() - v.front()) ? v.back() - v.front() : answer;
}
void split()
{
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			for (int d1 = 1; d1 <= N; d1++)
			{
				for (int d2 = 1; d2 <= N; d2++)
				{
					if (x + d1 + d2 > N) continue;
					if (y + d2 > N || y - d1 <= 0) continue;

					sol(x, y, d1, d2);
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	answer = 987654321;
}
int main()
{
	init();
	split();
	cout << answer;

	return 0;
}

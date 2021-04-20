#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct cctv
{
	int cx, cy, num;
};
int N, M, answer;
int arr[8][8];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<cctv> v;
// 1번 0,1,2,3  2번 01,23  3번 02,03,12,13  4번 012,013,023,123

void print(int temp[][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << temp[i][j] << " ";
		cout << endl;
	}
}
void cnt(int temp[][8])
{
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0) c++;
		}
	}
	//cout << c << endl;
	answer = (answer > c) ? c : answer;
}
void color(int idx,int dir,int temp[][8])
{
	queue<pair<int, int>> q;
	q.push({ v[idx].cx,v[idx].cy });

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		int nx = x + dx[dir], ny = y + dy[dir];

		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (temp[nx][ny] != 6)
			{
				if (temp[nx][ny] == 0) temp[nx][ny] = -1;
				q.push({ nx,ny });
			}
		}
	}
}
void fill(string s)
{
	int temp[8][8]; memcpy(temp, arr, sizeof(arr));
	//cout << s << endl;
	for (int i = 0; i < s.length(); i++)
	{
		if (v[i].num == 1)
			color(i, s[i] - '0', temp);
		else if (v[i].num == 2)
		{
			if (s[i] - '0' == 0)
			{
				color(i, 0, temp); color(i, 1, temp);
			}
			else
			{
				color(i, 2, temp); color(i, 3, temp);
			}
		}
		else if (v[i].num == 3)
		{
			if (s[i]-'0' < 2)	color(i, 0, temp);
			else color(i, 1, temp);

			if ((s[i]-'0') % 2 == 0) color(i, 2, temp);
			else color(i, 3, temp);
		}
		else if (v[i].num == 4)
		{
			if (s[i]-'0' < 3)color(i, 0, temp);
			else color(i, 1, temp);

			if(s[i] - '0' <2)color(i, 1, temp);
			else color(i, 2, temp);

			if(s[i] - '0' ==0) color(i, 2, temp);
			else color(i, 3, temp);
		}
		else if (v[i].num == 5)
		{
			color(i, 0, temp); color(i, 1, temp); color(i, 2, temp); color(i, 3, temp);
		}
	}
	
	cnt(temp);
	//print(temp);
}
void back(int idx,string s)
{
	if (idx == v.size())
	{
		fill(s); return;
	}
	else
	{
		for(int k =0;k<4;k++)
		{
			back(idx + 1, s + to_string(k));

			if (v[idx].num == 5) break;
			if (k == 1 && v[idx].num == 2) break;
		}
	}

}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)
			{
				cctv c; c.cx = i, c.cy = j, c.num = arr[i][j];
				v.push_back(c);
			}
		}
	}
	answer = 987654321;
}
int main()
{
	init();
	back(0, "");
	cout << answer;

	return 0;
}

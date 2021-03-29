#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int defalutMap[8][8];
int wallMap[8][8];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void virus(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && wallMap[nx][ny] == 0)
			{
				wallMap[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}
}
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			wallMap[i][j] = defalutMap[i][j];
	}
	/*
	for (int l = 0; l < N; l++)
	{
		for (int m = 0; m < M; m++)
			cout << wallMap[l][m] << " ";
		cout << endl;
	}
	*/
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	vector<pair<int, int>> zero;
	vector<pair<int, int>> two;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> defalutMap[i][j];
			if (defalutMap[i][j] == 0)
				zero.push_back({ i,j });
			else if (defalutMap[i][j] == 2)
				two.push_back({ i,j });
		}
	}
	
	int answer = 0;
	vector<string> v;
	for (int i = 0; i < zero.size() - 2; i++)
	{
		for (int j = i + 1; j < zero.size() - 1; j++)
		{
			for (int k = j + 1; k < zero.size(); k++)
			{
				string temp = "";
				temp += to_string(zero[i].first);
				temp += to_string(zero[i].second);
				temp += to_string(zero[j].first);
				temp += to_string(zero[j].second);
				temp += to_string(zero[k].first);
				temp += to_string(zero[k].second);

				v.push_back(temp);
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		init();
		wallMap[v[i][0]-'0'][v[i][1] - '0'] = 1;
		wallMap[v[i][2] - '0'][v[i][3] - '0'] = 1;
		wallMap[v[i][4] - '0'][v[i][5] - '0'] = 1;

		//바이러스가 퍼진다
		for (int j = 0; j < two.size(); j++)
			virus(two[j].first, two[j].second);
		/*
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < M; m++)
				cout << wallMap[l][m] << " ";
			cout << endl;
		}
		*/
		int result = 0;
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < M; m++)
			{
				if (wallMap[l][m] == 0)
				{
					result++;
				}
			}
		}

		answer = (answer < result) ? result : answer;
	}
	cout << answer;

	return 0;
}

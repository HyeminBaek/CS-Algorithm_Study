#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//7시~45

int N, M, answer;
int arr[50][50];
bool visited[2500];
vector<pair<int, int>> chicken, home;

void cal(vector<int> v)
{
	int sum = 0;
	
	for (int i = 0; i < home.size(); i++)
	{
		int temp = 987654321;
		for (int j = 0; j < v.size(); j++)
		{
			int result = abs(home[i].first - chicken[v[j]].first) + abs(home[i].second - chicken[v[j]].second);

			temp = (temp > result) ? result : temp;
		}
		sum += temp;
	}
	answer = (answer > sum) ? sum : answer;
}
void back(int cnt, int cur, int target, vector<int> v)
{
	if (cnt == target)
	{

		cal(v); return;
	}
	else
	{
		for (int k = cur; k < chicken.size(); k++)
		{
			if (!visited[k])
			{
				visited[k] = true;
				v.push_back(k);

				back(cnt + 1, k, target, v);

				v.pop_back();
				visited[k] = false;
			}
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
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 2) chicken.push_back({ i,j });
			else if (arr[i][j] == 1) home.push_back({ i,j });
		}
	}

	answer = 987654321;
}
int main()
{
	init();
	vector<int> v;
	back(0, 0, M, v);
	cout << answer;

	return 0;
}

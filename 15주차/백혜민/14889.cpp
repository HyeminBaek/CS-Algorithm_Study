#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, answer;
int arr[20][20];
bool visited[20];

int sum(vector<int> v)
{
	int total = 0;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
			total += arr[v[i]][v[j]] + arr[v[j]][v[i]]; //중복이 됨
	}

	return total;
}
void sol(int cur,int len)
{
	if (len == N / 2)
	{	
		vector<int> start, link;

		for (int i = 0; i < N; i++)
		{
			if (visited[i])	start.push_back(i);
			else link.push_back(i);
		}
		int startSum = sum(start), linkSum = sum(link);

		answer = (answer > abs(startSum - linkSum)) ? abs(startSum - linkSum) : answer;

		return;
	}
	for (int i = cur; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			sol(i,len + 1);
			visited[i] = false;
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	answer = 987654321;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
}
int main()
{
	init();
	sol(0,0);
	cout << answer / 2;

	return 0;
}

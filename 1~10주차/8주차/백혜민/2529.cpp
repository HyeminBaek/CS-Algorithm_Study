#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
using namespace std;

/*
위상 정렬이 필요한 경우는 그래프에서 반드시 자신보다 선행되어야 할 일이
끝내져야 작업에 들어갈 수 있는 경우

→ 부등호 앞자리가 결정되어야 뒷자리도 결정 가능

1. 그리디하게 최댓값은 9부터 9-K까지, 최소는 0부터 K까지 뽑음
2. 입력으로 받은 부등호를 만족시키면 -> 아니면 <- 방향으로 그래프를 생성
3. 이를 위상정렬한 결과가 정답
*/
int k;
char arr[9];
vector<int> MAX[10], MIN[10];
int MAXin[10], MINin[10];

pair<string, string> toplogical()
{
	priority_queue<int> q;
	for (int i = 9; i >= 9 - k; i--)
	{
		if (MAXin[i] == 0)
			q.push(i);
	}
	string max = "", min = "";
	for (int i = 9; i >= 9 - k; i--)
	{
		int cur = q.top();
		q.pop();
		max += to_string(cur);

		for (int next : MAX[cur]) //뭔말
			if (--MAXin[next] == 0) q.push(next);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i <= k; i++)
	{
		if (MINin[i] == 0)
			pq.push(i);
	}
	for (int i = 0; i <= k; i++)
	{
		int cur = pq.top();
		pq.pop();
		min += to_string(cur);

		for (int next : MIN[cur])
			if (--MINin[next] == 0) pq.push(next);
	}
	return { max,min };
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	int maxIdx = 9, minIdx = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];

		if (arr[i] == '<')
		{
			MAX[maxIdx - 1].push_back(maxIdx);
			MAXin[maxIdx--]++;

			MIN[minIdx].push_back(minIdx + 1);
			MINin[++minIdx]++;
		}
		else
		{
			MAX[maxIdx].push_back(maxIdx - 1);
			MAXin[--maxIdx]++;

			MIN[minIdx + 1].push_back(minIdx);
			MINin[minIdx++]++;
		}
	}
}
int main()
{
	init();
	pair<string, string> answer = toplogical();

	cout << answer.first << "\n" << answer.second;

	return 0;
}

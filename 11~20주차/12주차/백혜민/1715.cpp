#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int sol()
{
	int answer = 0;
	while (!pq.empty())
	{
		if (pq.size() == 1)	break;
		int arr[2];
		for (int k = 0; k < 2; k++)
		{
			arr[k] = pq.top();
			pq.pop();
		}
		answer += arr[0] + arr[1];
		pq.push(arr[0] + arr[1]);
	}
	
	return answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (N; N > 0; N--)
	{
		int x; cin >> x;
		pq.push(x);
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int M; long long answer;//틀린 요소
vector<int> v;

void sol()
{
	map<long long, long long> m;

	long long sum = 0LL;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i]; sum %= M;

		if (m.find(sum) != m.end()) m[sum]++;
		else m.insert({ sum,1 });

		if (sum == 0) answer++; //나누어떨어진경우
	}

	for (int i = 0; i < M; i++)
	{
		if (m.find(i) != m.end()) answer += (m[i] * (m[i] - 1)) / 2;
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
}
int main()
{
	init();
	sol();

	cout << answer;

	return 0;
}

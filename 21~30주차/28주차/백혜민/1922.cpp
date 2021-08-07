#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int uf[1001];
vector<pair<int, pair<int, int>>> v;

int unionFind(int a)
{
	if (uf[a] == a) return a;

	uf[a] = unionFind(uf[a]);
	return uf[a];
}
bool Unionfind(int a, int b)
{
	a = unionFind(a);
	b = unionFind(b);

	if (a == b) return false;

	uf[b] = a;
	return true;
}
void sol()
{
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (Unionfind(v[i].second.first, v[i].second.second))
		{
			answer += v[i].first;
		}
	}

	cout << answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M;

	for (M; M > 0; M--)
	{
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++) uf[i] = i;
}
int main()
{
	init();
	sol();

	return 0;
}

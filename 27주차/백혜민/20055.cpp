#include <iostream>
#include <vector>
using namespace std;

struct con
{
	int dur;
	bool robot;
};
int N, K;
vector<con> v;

void sol()
{
	int cnt = 0;

	while (1)
	{
		cnt += 1;

		//1
		v.insert(v.begin(), { v.back().dur,v.back().robot });
		v.pop_back(); v[N - 1].robot = false;
		
		//2
		for (int i = N - 2; i >= 0; i--)
		{
			if (!v[i + 1].robot && v[i + 1].dur >= 1 && v[i].robot)
			{
				v[i + 1].robot = true, v[i + 1].dur -= 1;
				v[i].robot = false;
			}
		}
		v[N - 1].robot = false;

		//3
		if (v[0].dur != 0)
		{
			v[0].robot = true, v[0].dur -= 1;
		}

		//4
		int left = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].dur == 0) left++;
		}
		if (left >= K) break;
	}
	cout << cnt;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
	{
		int d; cin >> d;
		v.push_back({ d,false });
	}
}
int main()
{
	init();
	sol();

	return 0;
}

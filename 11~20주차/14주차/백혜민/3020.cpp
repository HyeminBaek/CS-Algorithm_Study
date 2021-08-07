#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;
vector<int> seoksun;
vector<int> jongyu;

void sol()
{
	int minVal = N, cnt = 0;
	for (int i = 1; i <= H; i++)
	{
		int s = lower_bound(seoksun.begin(), seoksun.end(), i) - seoksun.begin();
		int j = upper_bound(jongyu.begin(), jongyu.end(), H - i) - jongyu.begin();

		s = seoksun.size() - s;
		j = jongyu.size() - j;

		if (minVal > s + j)
		{
			minVal = s + j;
			cnt = 1;
		}
		else if (minVal == s + j)
			cnt++;
	}

	cout << minVal << " " << cnt;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> H;

	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;

		if (i % 2 == 0)
			seoksun.push_back(x);
		else
			jongyu.push_back(x);
	}

	sort(seoksun.begin(), seoksun.end());
	sort(jongyu.begin(), jongyu.end());
}
int main()
{
	init();
	sol();

	return 0;
}

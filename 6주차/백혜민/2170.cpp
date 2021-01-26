#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	long long answer = 0;
	long long low = -1, high = -1;

	vector<pair<long long,long long>> v;
	for (N; N > 0; N--)
	{
		long long x, y; cin >> x >> y;

		int temp = x;
		if (x > y)
		{
			x = y;
			y = temp;
		}
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	for(int i =0;i<v.size();i++)
	{
		if (low == -1 && high == -1)
		{
			low = v[i].first, high = v[i].second;
		}
		else
		{
			if (v[i].first <= high)
			{
				if (v[i].second >= low)
				{
					low = (low > v[i].first) ? v[i].first : low;
					high = (high < v[i].second) ? v[i].second : high;
				}
			}
			else
			{
				//cout << high << " " << low << endl;
				answer += abs(high - low);
				low = v[i].first, high = v[i].second;
			}
		}
	}
	answer += abs(high - low);

	cout << answer;

	return 0;
}

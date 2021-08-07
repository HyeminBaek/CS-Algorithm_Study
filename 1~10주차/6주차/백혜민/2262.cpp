#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

int sol() //랭킹이 클 수록 먼저 묶여서 떨어져야 함
{
	int answer = 0;

	while (v.size() > 1)
	{
		int max = v.front(), maxIdx = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (max < v[i])
			{
				max = v[i]; maxIdx = i;
			}
		}
		if (maxIdx - 1 >= 0 && maxIdx + 1 < v.size())
		{
			int tmp = abs(v[maxIdx] - v[maxIdx - 1]), tmp2 = abs(v[maxIdx] - v[maxIdx + 1]);

			if (tmp > tmp2)	answer += tmp2;
			else answer += tmp;
		}
		else
		{
			if (maxIdx == 0) answer += abs(v[maxIdx] - v[maxIdx + 1]);
			else if(maxIdx == v.size()-1) answer += abs(v[maxIdx] - v[maxIdx - 1]);
		}

		v.erase(v.begin() + maxIdx);
	}

	return answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}

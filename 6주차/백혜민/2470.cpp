#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<long long> v;
	for (int i = 0; i < N; i++)
	{
		long long x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	long long low = 0, high = v.size() - 1;

	long long answer = v[0]+v.back();
	long long l = 0, h = v.size()-1;
	while (low < high)
	{
		if (abs(answer) > abs(v[low] + v[high]))
		{
			answer = abs(v[low] + v[high]);
			l = low, h = high;
		}
		if (v[low] + v[high] > 0)
			high--;
		else if (v[low] + v[high] == 0)
		{
			l = low, h = high; break;
		}
		else
			low++;
	}

	cout << v[l] << " " << v[h];

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int minv, maxv;
vector<int> num, oper;

void doOper(vector<int> v)
{
	int result = num[0];
	for (int i = 1; i < num.size(); i++)
	{
		switch (v[i - 1])
		{
		case 0:
			result += num[i]; break;
		case 1:
			result -= num[i]; break;
		case 2:
			result *= num[i]; break;
		case 3:
			result /= num[i]; break;
		}
	}

	maxv = max(maxv, result);
	minv = min(minv, result);
}
//연산자를 배치시키는 경우의 수를 구한다고 생각
void solution()
{
	do
	{
		vector<int> v;
		for (int i = 0; i < oper.size(); i++)
			v.push_back(oper[i]);
		
		doOper(v);
	} while (next_permutation(oper.begin(), oper.end()));
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		num.push_back(x);
	}

	for (int i = 0; i < 4; i++)
	{
		int x; cin >> x;

		for (int j = 0; j < x; j++)
			oper.push_back(i);
	}

	minv = 987654321, maxv = -987654321;
}
int main()
{
	init();
	solution();

	cout << maxv << "\n" << minv;

	return 0;
}

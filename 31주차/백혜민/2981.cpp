#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> v, answer;

/*
인접한 두 수 차끼리의 gcd, gcd들의 약수들
*/

void print()
{
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}
int euclid(int A,int B)
{
	if (A % B != 0) return euclid(B, A % B);
	else return B;
}
void sol()
{
	int gcd = v[1] - v[0];
	for (int i = 1; i < v.size()-1; i++)
		gcd = euclid(gcd, v[i+1]-v[i]);
	
	for (int j = 2; j <= sqrt(gcd); j++)
	{
		if (gcd % j == 0)
		{
			answer.push_back(j);
			answer.push_back(gcd / j);
		}
	}
	answer.push_back(gcd);

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()),answer.end());
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());
}
int main()
{
	init();
	sol();
	print();

	return 0;
}

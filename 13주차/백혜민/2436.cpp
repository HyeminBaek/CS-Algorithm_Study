#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

/*
1. 최대공약수 최소공배수를 입력받고 최소공배수를 최대공약수로 나눈다
∵ 최대공약수는 꼭 포함되어야 하므로 고려할 필요가 없음
2. 약수의 pair 쌍이 서로소인 것을 구함 
3. 2에 최대공약수를 곱한다
*/
int gcd;
priority_queue < pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
int euclid(int a,int b)
{
	while (1)
	{
		if (a%b == 0)	return b;

		int temp = a % b;
		a = b;
		b = temp;
	}
}
void sol(int num)
{
	//최대공약수가 1
	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num%i != 0) continue;
		if (euclid(num / i, i) == 1)
			pq.push({ (num / i * gcd) + (i*gcd),{i*gcd,num / i * gcd} });
	}
}
int init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int lcm;  cin >> gcd >> lcm;

	return lcm / gcd;
}
int main()
{
	int num = init();
	sol(num);
	cout << pq.top().second.first <<" "<< pq.top().second.second;

	return 0;
}

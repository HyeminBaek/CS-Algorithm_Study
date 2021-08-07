#include <iostream>
using namespace std;

//M-GCD(N,M)

int N, M;

int gcd(int x, int y)
{
	if (x%y != 0)
	{
		int temp = y;
		y = x % y;
		x = temp;

		return gcd(x, y);
	}
	else return y;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
}
int main()
{
	init();
	cout << M - gcd(N, M);

	return 0;
}

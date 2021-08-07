#include <iostream>
#include <string>
using namespace std;

char arr[10000][10000];
void make_star(int N, int x, int y)
{
	if ((x/N)%3 == 1 && (y/N)%3 == 1) arr[x][y] = ' ';
	else
	{
		if (N / 3 == 0)
			arr[x][y] = '*';
		else
			make_star(N / 3, x, y);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			make_star(N, i, j);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j];
		cout << endl;
	}
	return 0;
}

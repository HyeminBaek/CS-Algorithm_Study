#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> v;
int dice[6] = { 5,3,4,1,2,0 };

void sol()
{
	int answer = 0;
	for (int i = 0; i < 6; i++) //A~F가 위에 오는 경우
	{
		int up = v[0][i], bt = v[0][dice[i]], idx = i;
		int sum = 0;

		for (int j = 0; j < 6; j++)
		{
			if (j == idx || j == dice[idx]) continue;

			sum = (sum < v[0][j]) ? v[0][j] : sum;
		}

		for (int j = 1; j < N; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (v[j][k] == up)
				{
					bt = v[j][k], idx = k;
					up = v[j][dice[idx]];
					break;
				}
			}
			int temp = 0;
			for (int k = 0; k < 6; k++)
			{
				if (k == idx || k == dice[idx]) continue;

				temp = (temp < v[j][k]) ? v[j][k] : temp;
			}

			sum += temp;
		}

		answer = (answer < sum) ? sum : answer;
	}

	cout << answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> t;
		for (int j = 0; j < 6; j++)
		{
			int x; cin >> x;
			t.push_back(x);
		}

		v.push_back(t);
	}
}
int main()
{
	init();
	sol();

	return 0;
}

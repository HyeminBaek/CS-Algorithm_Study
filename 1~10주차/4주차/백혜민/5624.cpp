#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool pvisited[200001] = { false, };
	bool mvisited[200001] = { false, };

	int N; cin >> N;

	int arr[5001];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (2 * arr[0] < 0) mvisited[arr[0] + arr[0]] = true;
	else pvisited[arr[0] + arr[0]] = true;

	int answer = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] - arr[j] < 0)
			{
				if (mvisited[abs(arr[i] - arr[j])])
				{
					answer++; break;
				}
			}
			else
			{
				if (pvisited[arr[i] - arr[j]])
				{
					answer++; break;
				}
			}
		}
		for (int j = 0; j <= i; j++)
		{
			if (arr[i] + arr[j] < 0)
				mvisited[abs(arr[i] + arr[j])] = true;
			else
				pvisited[arr[i] + arr[j]] = true;
		}
	}

	cout << answer;

	return 0;
}

#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;


int N, SIZE;
int arr[64][64];
bool visited[64][64];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


void print()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int count(int i, int j)
{
	queue <pair<int, int>> q;
	q.push({ i,j }); visited[i][j] = 1;

	int cnt = 1;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();


		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];


			if (0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE)
			{
				if (!visited[nx][ny] && arr[nx][ny] > 0)
				{
					cnt += 1; q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}


	return cnt;
}
int findMax()
{
	int answer = 0;


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (!visited[i][j] && arr[i][j] > 0)
			{
				answer = max(answer, count(i, j));
			}
		}
	}


	return answer;
}
int leftSum()
{
	int answer = 0;


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			answer += arr[i][j];
		}
	}


	return answer;
}
void melt()
{
	int tmp[64][64]; memcpy(tmp, arr, sizeof(arr));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int cnt = 0;

			if (arr[i][j] == 0) continue;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE)
				{
					if (arr[nx][ny] > 0) cnt++;
				}
			}
			if (cnt < 3) tmp[i][j] -= 1;
		}
	}
	memcpy(arr, tmp, sizeof(tmp));
}
void spin(int sx, int sy, int l)
{
	queue<int> q;
	for (int i = sx; i < sx + pow(2.0, l); i++)
	{
		for (int j = sy; j < sy + pow(2.0, l); j++)
		{
			q.push(arr[i][j]);
		}
	}

	for (int j = sy + pow(2.0, l) - 1; j >= sy; j--)
	{
		for (int i = sx; i < sx + pow(2.0, l); i++)
		{
			arr[i][j] = q.front(); q.pop();
		}
	}
}
void split(int l)
{
	for (int i = 0; i < SIZE; i += pow(2.0, l))
	{
		for (int j = 0; j < SIZE; j += pow(2.0, l))
		{
			spin(i, j, l);
		}
	}
	melt();
}
void init(int& Q)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> Q; SIZE = pow(2.0, N);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cin >> arr[i][j];


			visited[i][j] = 0;
		}
	}
}
int main()
{
	int Q;
	init(Q);


	for (Q; Q > 0; Q--)
	{
		int l; cin >> l;
		split(l);
	}


	cout << leftSum() << "\n";
	cout << findMax();


	return 0;
}

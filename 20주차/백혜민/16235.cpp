#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct tree
{
	int x, y, age;
};
bool treeSort(tree a, tree b)
{
	return a.age < b.age;
}

int N, K;
int nut[10][10], arr[10][10]; //양분, 현 상태
deque<tree> v;

void spring();
void summer(vector<tree>, vector<tree>);
void fall(vector<tree>);
void winter();

void init();

int main()
{
	init();
	for (K;K>0;K--)
		spring();

	cout << v.size();

	return 0;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> nut[i][j];
			arr[i][j] = 5;
		}
	}
	for (M; M > 0; M--)
	{
		int r, c, y; cin >> r >> c >> y;

		v.push_back({ r - 1,c - 1,y });
	}
}
void spring()
{
	vector<tree> dead, spread;

	for (int i = 0; i < v.size(); i++)
	{
		tree cur = v.front(); v.pop_front();

		if (arr[cur.x][cur.y] < cur.age)
		{
			dead.push_back(cur);
			i -= 1;
		}
		else
		{
			arr[cur.x][cur.y] -= cur.age;
			cur.age += 1;
			v.push_back(cur);

			if (cur.age % 5 == 0) spread.push_back(cur);
		}
	}
	summer(dead, spread);
}
void summer(vector<tree> dead, vector<tree> spread)
{
	for (int i = 0; i < dead.size(); i++)
	{
		tree cur = dead[i];
		arr[cur.x][cur.y] += cur.age / 2;
	}

	fall(spread);
}
void fall(vector<tree> spread)
{
	int dx[] = { -1,1,0,0,1,-1,-1,1 };
	int dy[] = { -1,-1,1,-1,0,0,1,1 };

	for (int i = 0; i < spread.size(); i++)
	{
		tree cur = spread[i];
		for (int k = 0; k < 8; k++)
		{
			int nx = cur.x + dx[k], ny = cur.y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				v.push_front({ nx,ny,1 });
			}
		}
	}

	winter();
}
void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			arr[i][j] += nut[i][j];
	}
}

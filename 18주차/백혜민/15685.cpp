#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//1시 5분~
set<pair<int, int>> point;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int check()
{
	int answer = 0;

	for (int i = 0; i <= 99; i++) //범위문제로 틀림
	{
		for (int j = 0; j <= 99; j++)
		{
			//if (point.find({ i,j })!=point.end()) cout << i << " " << j << endl;
			if (point.find({ i,j }) != point.end() && point.find({ i + 1,j }) != point.end())
			{
				if (point.find({ i,j + 1 }) != point.end() && point.find({ i + 1,j + 1 }) != point.end())
					answer++;
			}
		}
	}

	return answer;
}
void curve(int x,int y,int d,int g)
{
	vector<int> dir; dir.push_back(d); //0세대

	for (int i = 1; i <= g; i++)//g세대까지
	{
		for (int j = dir.size() - 1; j >= 0; j--)
			dir.push_back((dir[j] + 1) % 4);
	}

	int cx = x, cy = y; point.insert({ cx,cy });
	for (int i = 0; i < dir.size(); i++)
	{
		int nx = cx + dx[dir[i]], ny = cy + dy[dir[i]];
		point.insert({nx,ny});
		cx = nx, cy = ny;
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (N; N > 0; N--)
	{
		int x, y, d, g; cin >> x >> y >> d >> g;
		curve(x, y, d, g);
	}
}
int main()
{
	init();
	cout << check();

	return 0;
}

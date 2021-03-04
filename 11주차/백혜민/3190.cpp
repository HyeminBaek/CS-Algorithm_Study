#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
vector<pair<int, char>> changeDir; 

int dx[] = { 0,0,-1,1 };//오R,왼L,위U,아D 순
int dy[] = { 1,-1,0,0 };

void next(int x,int y,int& nx, int& ny, char dir)
{
	if (dir == 'R')
	{
		nx = x + dx[0], ny = y + dy[0];
	}
	else if (dir == 'L')
	{
		nx = x + dx[1], ny = y + dy[1];
	}
	else if (dir == 'U')
	{
		nx = x + dx[2], ny = y + dy[2];
	}
	else
	{
		nx = x + dx[3], ny = y + dy[3];
	}
}
char move(char cur, char chg)//현재 방향과 바꿀 방향이 매개변수
{
	if (cur == 'R')
	{
		if (chg == 'D') return 'D';
		else return 'U';
	}
	else if (cur == 'L')
	{
		if (chg == 'D') return 'U';
		else return 'D';
	}
	else if (cur == 'U')
	{
		if (chg == 'D') return 'R';
		else return 'L';
	}
	else
	{
		if (chg == 'D') return 'L';
		else return 'R';
	}
}
int bfs()
{
	int x = 1, y = 1; int tx = 1, ty = 1; int time = 0; //헤드와 꼬리 좌표
	char dir = 'R', tdir = 'R'; //헤드와 꼬리 방향

	map[1][1] = 1;

	vector<pair<pair<int, int>, char>> turn;
	while (1)
	{
		int nx = -1, ny = -1, ntx = -1, nty = -1;
		next(x, y, nx, ny, dir); next(tx, ty, ntx, nty, tdir);
		
		if (0 < nx&&nx <= N && 0 < ny&&ny <= N)
		{
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = 1; map[tx][ty] = 0;
				x = nx, y = ny, tx = ntx, ty = nty; time += 1;
			}
			else if (map[nx][ny] == -1)
			{
				map[nx][ny] = 1; 
				x = nx, y = ny; time += 1;
			}
			else return time + 1;
		}
		else return time + 1;

		if (!changeDir.empty() && time == changeDir.front().first)
		{
			dir = move(dir, changeDir.front().second);
			
			turn.push_back({ {x,y},dir });
			changeDir.erase(changeDir.begin());
		}
		if (!turn.empty() && tx == turn.front().first.first && ty == turn.front().first.second)
		{
			tdir = turn.front().second; turn.erase(turn.begin());
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K; cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y; cin >> x >> y;
		map[x][y] = -1;//치즈 위치 표시
	}
	int L; cin >> L;
	for (int i = 0; i < L; i++)
	{
		int s; char d; cin >> s >> d;
		changeDir.push_back({ s,d });
	}
}
int main()
{
	init();
	cout << bfs();
	
	return 0;
}

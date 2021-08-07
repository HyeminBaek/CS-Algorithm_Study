#include <iostream>
#include <cstring>
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[7];

void sol(int dir) //동 1 서 2 북 3 남 4
{
	int nx = x, ny = y;
	switch (dir)
	{
	case 1:
		ny += 1;
		break;
	case 2:
		ny -= 1;
		break;
	case 3:
		nx -= 1;
		break;
	case 4:
		nx += 1;
		break;
	}
	if (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		int temp[7]; memcpy(temp, dice, sizeof(dice));
		switch (dir)
		{
		case 1:
			dice[1] = temp[4], dice[3] = temp[1], dice[4] = temp[6], dice[6] = temp[3];
			break;
		case 2:
			dice[1] = temp[3], dice[3] = temp[6], dice[4] = temp[1], dice[6] = temp[4];
			break;
		case 3:
			dice[1] = temp[5], dice[2] = temp[1], dice[5] = temp[6], dice[6] = temp[2];
			break;
		case 4:
			dice[1] = temp[2], dice[2] = temp[6], dice[5] = temp[1], dice[6] = temp[5];
			break;
		}
		if (map[nx][ny] == 0) map[nx][ny] = dice[6];
		else dice[6] = map[nx][ny], map[nx][ny] = 0;
		x = nx, y = ny;

		cout << dice[1]<<"\n";
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
}
int main()
{
	init();
	for (K; K > 0; K--)
	{
		int d; cin >> d;
		sol(d);
	}

	return 0;
}

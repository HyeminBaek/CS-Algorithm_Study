#include<iostream>
#include <queue>
using namespace std;
 
int sx, sy, ex, ey;
int map[16][16];
bool visited[16][16];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
 
bool bfs()
{
    queue<pair<int, int>> q;
    q.push({ sx,sy }); visited[sx][sy] = true;
 
    bool flag = false;
 
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second; q.pop();
 
        if (x == ex && y == ey)
        {
            flag = true; break;
        }
 
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < 16 && 0 <= ny && ny < 16)
            {
                if (!visited[nx][ny] && map[nx][ny] !=1)
                {
                    visited[nx][ny] = true; q.push({ nx,ny });
                }
            }
        }
    }
 
    return flag;
}
int main(int argc, char** argv)
{
    int test_case;
 
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int T; cin >> T;
 
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                char c; cin >> c;
                map[i][j] = c - '0';
                visited[i][j] = false;
                if (map[i][j] == 2) sx = i, sy = j;
                else if (map[i][j] == 3) ex = i, ey = j;
            }
        }
        cout << '#' << test_case << " " << bfs() << "\n";
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct magic
{
    int rain; bool cloud;
};
int N;

magic arr[51][51];

queue<pair<int, int>> mov;
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

void print()
{
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << arr[i][j].cloud << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << arr[i][j].rain << " ";
        cout << endl;
    }
}
void sumofleft()
{
    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            answer += arr[i][j].rain;
    }

    cout << answer;
}
void makecld()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j].rain >= 2 && !arr[i][j].cloud)
            {
                arr[i][j].cloud = true;
                arr[i][j].rain -= 2;
            }
            else if (arr[i][j].cloud)
                arr[i][j].cloud = false;
        }
    }
}
void cldmov()
{
    magic tmp[51][51];
    memcpy(tmp, arr, sizeof(arr));

    vector<pair<int, int>> newcld;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j].cloud) //구름이면 d방향으로 s칸 이동
            {
                int nx = i, ny = j;
                for (int c = 0; c < mov.front().second; c++)
                {
                    nx += dx[mov.front().first];
                    ny += dy[mov.front().first];

                    if (nx == 0) nx = N;
                    else if (nx > N)nx = 1;
                    if (ny == 0) ny = N;
                    else if (ny > N)ny = 1;
                }

                tmp[i][j].cloud = false; //이전 위치에 구름이 없음
                tmp[nx][ny].cloud = true; //새 위치에 구름이 위치
                tmp[nx][ny].rain += 1; //2번 연산

                newcld.push_back({ nx,ny });
            }
        }
    }
    memcpy(arr, tmp, sizeof(tmp));

    for (int i = 0; i < newcld.size(); i++)
    {
        if (!arr[newcld[i].first][newcld[i].second].cloud) arr[newcld[i].first][newcld[i].second].cloud = true;
    }
    
    memcpy(tmp, arr, sizeof(arr));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j].cloud)
            {
                int cnt = 0;
                for (int k = 1; k < 8; k += 2)
                {
                    int cx = i + dx[k], cy = j + dy[k]; //물복사 버그

                    if (0 < cx && cx <= N && 0 < cy && cy <= N && arr[cx][cy].rain > 0)
                    {
                        cnt += 1;
                    }
                }
                tmp[i][j].rain += cnt;
            }
        }
    }
    memcpy(arr, tmp, sizeof(tmp));
}
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M; cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;  cin >> x;
            arr[i][j].rain = x;
        }
    }
    arr[N][1].cloud = true, arr[N][2].cloud = true, arr[N - 1][1].cloud = true, arr[N - 1][2].cloud = true;

    for (M; M > 0; M--)
    {
        int d, s; cin >> d >> s;
        mov.push({ d - 1,s });
    }
}
int main()
{
    init();
    while (!mov.empty())
    {
        cldmov();
        //cout << "after cldmov\n";
        //print();
        makecld();
        //cout << "after makecld()\n";
        //print();
        mov.pop();
    }
    sumofleft();

    return 0;
}

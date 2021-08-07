#include<iostream>
#include <cstring>
#include <queue>
#include <map>

const int MAX = 20;
using namespace std;

int n, m;
string board[MAX][MAX];
int visit[MAX][MAX][4][16];
map<string, int> order;
pair<int, int> movdir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //상 하 좌 우


void BFS(int test_case){
    queue<pair<pair<int, int>, pair<int, int>>> q;    //좌표, 방향
    q.push({{0, 0}, {3, 0}});
    visit[0][0][3][0]++;
    
    while(!q.empty()){
        bool flag = true;
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second.first;
        int memory = q.front().second.second;
        q.pop();

        if(board[y][x] == "@"){
            cout << "#" << test_case << " " << "YES" << "\n";
            return;
        }

        if("0" <= board[y][x] && board[y][x] <= "9"){
            memory = board[y][x][0] - '0';
            flag = false;
        }

        if(flag){
            switch (order[board[y][x]]){
                case 0:    //>
                    d = 2;
                    break;
                
                case 1:    //<
                    d = 3;
                    break;
                
                case 2:    //^
                    d = 0;
                    break;

                case 3:    //v
                    d = 1;
                    break;

                case 4:    //_
                    if(memory == 0) 
                        d = 3;
                    else
                        d = 2;
                    break;

                case 5:    //|
                    if(memory == 0)
                        d = 1;
                    else
                        d = 0;
                    break;

                case 6:    //+
                    if(memory == 15)
                        memory = 0;
                    else
                        memory++;
                    break;

                case 7:    //-
                    if(memory == 0)
                        memory = 15;
                    else
                        memory--;
                    break;

                case 8:    //.
                    break;

                default:
                    break;
            }
        }

        if(board[y][x] == "?"){
            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(ny < 0 || n <= ny || nx < 0 || m <= nx){
                    if(ny < 0) ny = n-1;
                    else if(n == ny) ny = 0;
                    
                    if(nx < 0) nx = m-1;
                    else if(m == nx) nx = 0;
                }

                if(visit[ny][nx][i][memory] == false){
                    visit[ny][nx][i][memory] = true;
                    q.push({{ny, nx}, {i, memory}});
                }
            }
        }
        else{
            int ny = y + movdir[d].first;
            int nx = x + movdir[d].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx){
                if(ny < 0) ny = n-1;
                else if(n == ny) ny = 0;
                
                if(nx < 0) nx = m-1;
                else if(m == nx) nx = 0;
            }

            if(visit[ny][nx][d][memory] == false){
                visit[ny][nx][d][memory] = true;
                q.push({{ny, nx}, {d, memory}});
            }
        }
    }

    cout << "#" << test_case << " " << "NO" << "\n";
    return;
}

void setting(){
    order["<"] = 0; order[">"] = 1; order["^"] = 2;
    order["v"] = 3; order["_"] = 4; order["|"] = 5;
    order["+"] = 6; order["-"] = 7; order["."] = 8;
    order["?"] = 9; order["."] = 10;
}

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);

    setting();
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(visit, false, sizeof(visit));
		cin >> n >> m;
        for(int i=0; i<n; i++){
           	string s; cin >> s;
            for(int j=0; j<m; j++){
                board[i][j] = s[j];
            }
        }
        
		BFS(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
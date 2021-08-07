#include<iostream>
#include <cstring>

using namespace std;

int n;
int map[10][10];
pair<int, int> movdir[] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(map, 0, sizeof(map));
		cin >> n;
        int temp = n;
        int row = 0, col = 0;
        int count = 1;
        for(int i=0; i<temp; i++){
            map[row][col++] = count++;
        }
		col--; temp--;

        int d = 0;
        while(temp != 0){
			for(int i=0; i<2; i++){
                for(int j=0; j<temp; j++){
               		row = row + movdir[d].first;
                    col = col + movdir[d].second;
                    
                    map[row][col] = count++;
                }
                d = d+1 > 3 ? 0 : d+1;
            }
            
            temp--;
        }
		
        cout << "#" << test_case << "\n";
        for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << map[i][j] << " ";
            }
            cout << "\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
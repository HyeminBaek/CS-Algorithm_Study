#include <iostream>
#include <cstring>

using namespace std;

int Indegree[10010];
int Outdegree[10010];
bool check[10010];

int main(){
    int tc = 1;
    int Max = -1, Min = 987654321;
    int root = -1, edge = 0;
    bool flag = true;

    while(tc){
        int a, b;
        cin >> a >> b;
        
        check[a] = true;
        check[b] = true;

        if(a == -1 && b == -1)
            break;
        if(a != 0 && b != 0){
            Max = max(Max, max(a, b));
            Min = min(Min, min(a, b));
        }

        if(a == 0 && b == 0){
            for(int i=Min; i<=Max; i++){
                if(Indegree[i] == 0 && Outdegree[i] != 0){
                    if(root != -1)
                        flag = false;
                    root = i;
                }
            }

            if(root == -1)
                flag = false;
            
            for(int i=Min; i<=Max; i++){
                if(Indegree[i] >= 2)
                    flag = false;
            }

           int node = 0;
            for(int i=Min; i<= Max; i++){
                if(check[i] == true)
                    node++;
            }

            if(edge+1 != node)
                flag = false;

            if(flag || edge == 0){
                cout << "Case " << tc << " is a tree.\n";
            }
            else{
                cout << "Case " << tc << " is not a tree.\n";
            }

            memset(Indegree, 0, sizeof(Indegree));
            memset(Outdegree, 0, sizeof(Outdegree));
            memset(check, false, sizeof(check));

            tc++;
            Max = -1; Min = 987654321;
            root = -1; edge = 0;
            flag = true;
            continue;
        }

        Outdegree[a]++;
        Indegree[b]++;
        edge++;
    }
}
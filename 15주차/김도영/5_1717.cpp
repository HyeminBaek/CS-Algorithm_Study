#include <iostream>

const int MAX = 1000001;
using namespace std;

int n, m;
int arr[MAX];
int parent[MAX];

int Find(int x){
    if (x == parent[x])
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    int op, a, b;
    for(int i=0; i<m; i++){
        cin >> op >> a >> b;
        if(op == 0){
            Union(a, b);
        }
        else{
            if(Find(a) == Find(b)){
                cout << "YES" << "\n";
            }
            else
                cout << "NO" << "\n";
        }
    }


}
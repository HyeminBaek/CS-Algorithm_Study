#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
long long B;
map<long long,vector<vector<int>>> memo;

vector<vector<int>> multiplyMatrix(vector<vector<int>> m1, vector<vector<int>> m2){
    int n = (int)m1.size();
    vector<vector<int>> result(n);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            int elem=0;
            for(int i=0;i<n;i++)    elem += m1[r][i]*m2[i][c];
            elem %= 1000;
            result[r].push_back(elem);
        }
    }
    return result;
}

vector<vector<int>> matrixSquareOfB(long long b){
    if(memo[b].size()!=0) return memo[b];
    
    if(b%2==1){
        memo[b] = multiplyMatrix(matrixSquareOfB(1), matrixSquareOfB(b-1));
        return memo[b];
    }
    else{
        memo[b] = multiplyMatrix(matrixSquareOfB(b/2), matrixSquareOfB(b/2));
        return memo[b];
    }
}

void printMatrix(vector<vector<int>> m){
    int n = (int)m.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j];
            if(j<n-1)   cout<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int elem;
    cin>>N>>B;
    vector<vector<int>> matrix(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>elem;
            elem%=1000;
            matrix[i].push_back(elem);
        }
    }
    memo[1] = matrix;
    printMatrix(matrixSquareOfB(B));
    return 0;
}

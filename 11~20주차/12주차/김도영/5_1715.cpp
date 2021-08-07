#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

int main(){
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++){
        int a; cin >> a;
        pq.push(-1 * a);
    }

    int total = 0, cnt = 0;
    int a = 0, b = 0;
    while(!pq.empty()){
        cnt++;
        a = -1 * pq.top(); pq.pop();
        b = -1 * pq.top(); pq.pop();

       total += (a + b);
       if(cnt == n-1) break;
       pq.push(-1 * (a+b));
    }

    cout << total;

}
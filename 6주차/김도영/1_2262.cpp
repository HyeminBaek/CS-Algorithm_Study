#include <iostream>
#include <vector>

using namespace std;

int n, a, ans = 0;
vector<int> v;
vector<int> temp;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }
    
    while(v.size() != 0){
        int idx = 0, Max = 0;
        for(int i = 0; i<v.size(); i++){
            if(Max < v[i]){
                Max = v[i];
                idx = i;
            }
        }

        if(idx == 0)
            ans += v[idx] - v[idx+1];
        else if(idx == v.size()-1)
            ans += v[idx] - v[idx-1];
        else
            ans += (v[idx] - max(v[idx-1], v[idx+1]));
            
        v.erase(v.begin()+idx);
    }

    cout << ans;
}
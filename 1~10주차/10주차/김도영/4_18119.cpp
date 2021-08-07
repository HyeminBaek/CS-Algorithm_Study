#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void DecToBin(int dec){
    cout << "\n";
    string bin;
    while(dec != 0){
        bin = to_string((dec%2)) + bin;
        dec /= 2;
    }
    
    cout << bin << "\n";
}

int main(){
    int alpha = 0;
    for(int i=0; i<26; i++){
        alpha = alpha + (1<<i);
    }

    cin >> n >> m;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;

        int bit = 0, num;
        for(int j=0; j<s.size(); j++){
            num = s[j]-'a';
            bit |= (1 << num);
        }

        v.push_back(bit);
        //DecToBin(bit);
    }

    int o; char x;
    for(int query=0; query<m; query++){
        cin >> o >> x;

        int num = x-'a';
        alpha ^= (1 << num);

        int count = 0;
        for(int i=0; i<v.size(); i++){
            if((v[i] & alpha) == v[i]){
                count++;
            }
        }

        cout << count << "\n";
    }
}
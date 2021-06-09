#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T; cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N,min=987654321; cin >> N;
        vector<int> v;
        for (N; N > 0; N--)
        {
            int x; cin >> x;
            v.push_back(x);
            
            min = (min>x)?x:min;
        }

        int sum[1000][2] = { 0, };
        sum[0][0] = v[0], sum[0][1] = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            sum[i][0] = sum[i - 1][0]^v[i];
            sum[i][1] = sum[i - 1][1]+v[i];
        }

        cout << "#" << test_case << " ";
        if (sum[v.size()-1][0] == 0) cout << sum[v.size()-1][1]-min<<"\n";
        else cout <<"NO\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

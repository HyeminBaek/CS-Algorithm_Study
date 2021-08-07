#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
typedef set<string>::iterator ITER;
int T, N;
set<string> st;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        st.clear();
        for (int i = 0; i < N; i++) {
            cin >> s;
            st.insert(s);
        }
        cout << "#" << tc << "\n";
        for (ITER iter = st.begin(); iter != st.end(); iter++) {
            cout << *iter << "\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int T;

string solve(int len, string s) {
    stack<char> st;
    for (int i = 0; i < len; ++i) {
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }

    string ret = "";
    while (!st.empty()) {
        ret = st.top() + ret;
        st.pop();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int len;
        string s;
        cin >> len >> s;
        cout << '#' << test_case << ' ' << solve(len, s) << '\n';
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string str;
int alphabet_count[26];
vector<string> NUM_STRING = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string str_delete_order = "ZWXGHSVINF";
string int_delete_order = "0268375914";

void preprocess() {
    for(char c: str) {
        alphabet_count[c-'A']++;
    }
}

string add_string(vector<int>& tmp, int& pos) {
    string ret = "";
    for(int x: tmp) {
        string erase = NUM_STRING[x];
        int loop_count = alphabet_count[str_delete_order[pos] - 'A'];
        for(int i = 0; i < loop_count; i++) {
            ret += int_delete_order[pos];
            for(auto c: erase) {
                alphabet_count[c-'A']--;
            }
        }
        pos += 1;
    }
    return ret;
}

string solve() {
    preprocess();
    string ret = "";
    int pos = 0;

    vector<int> tmp;
    tmp = {0, 2, 6, 8};
    ret += add_string(tmp, pos);

    tmp.clear();
    tmp = {3, 7};
    ret += add_string(tmp, pos);

    tmp.clear();
    tmp = {5};
    ret += add_string(tmp, pos);

    tmp.clear();
    tmp = {9};
    ret += add_string(tmp, pos);

    tmp.clear();
    tmp = {1, 4};
    ret += add_string(tmp, pos);

    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int T_case = 1; T_case <= t; ++T_case) {
        cin >> str;
        cout << "Case #" << T_case << ": " << solve() << "\n";
    }
}

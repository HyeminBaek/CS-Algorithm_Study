#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
string s = "";
string result;
vector<string> answer;
string mini = "9999999999";
string maxi = "";
bool visited[10];
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		s.push_back(a);
	}
}
void solve(char c, int num,int cnt, string gg) {
	if (cnt == N) {
		answer.push_back(gg);
		return;
	}
		for (int j = 0; j < 10; j++) {
			if (!visited[j]) {
				if (c == '<' && num < j) {
					visited[j] = true;
					gg.push_back(j + 48);
					solve(s[cnt + 1], j, cnt + 1, gg);
					gg.pop_back();
					visited[j] = false;
				}
				else if (c == '>' && num > j) {
					visited[j] = true;
					gg.push_back(j + 48);
					solve(s[cnt + 1], j, cnt + 1, gg);
					gg.pop_back();
					visited[j] = false;
				}
			}
	}
	return;
}
int main(void) {
	init();
	for (int i = 0; i < 10; i++) {
		visited[i] = true;
		string gg = "";
		gg.push_back(i + 48);
		solve(s[0], i, 0 ,gg );
		gg.pop_back();
		visited[i] = false;
	}
	
	for (int i = 0; i < answer.size(); i++) {
		string bb = answer[i];
		if (bb > maxi) {
			maxi = bb;
		}
		if (bb < mini) {
			mini = bb;
		}
	}
	cout << maxi << '\n' << mini;
	return 0;
}

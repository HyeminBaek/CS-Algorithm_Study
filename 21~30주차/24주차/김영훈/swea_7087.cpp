#include<iostream>
#include<string>
using namespace std;
string s;
int check[26];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	int T, N;

	cin >> T;
	for (int i = 0; i < 26; i++) {
		check[i] = -1;
	}
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> s;
			check[s[0] - 'A'] = tc;
		}
		int answer = 0;
		for (int i = 0; i < 26; i++) {
			if (check[i] != tc) {
				break;
			}
			answer++;
		}
		cout << "#" << tc << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
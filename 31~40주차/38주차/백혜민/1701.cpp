#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5001;
string W;

int KMP(string S)
{
	int fail[SIZE] = { 0, }; int max = 0;

	for (int i = 1, j = 0; i < S.length(); i++) {
		while (j > 0 && S[i] != S[j]) j = fail[j - 1];
		if (S[i] == S[j]) fail[i] = ++j;

		max = (max < fail[i]) ? fail[i] : max;
	}

	return max;
}
void solution()
{
	int answer = 0;
	for (int k = 0; k < W.length(); k++) {
		int max = KMP(W.substr(k, W.length()));

		answer = (answer < max) ? max : answer;
	}
	cout << answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> W;
}
int main()
{
	init();
	solution();

	return 0;
}
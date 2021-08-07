#include<iostream>
#include<vector>

using namespace std;
int N;
vector<pair<char,char>> node[26];
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		node[a - 65].push_back({ b,c });
	}
}

void preorder(char c) {
	if (c == '.') {
		return;
	}
	cout << c;
	preorder(node[c - 65][0].first);
	preorder(node[c - 65][0].second);
}
void inorder(char c) {
	if (c == '.') {
		return;
	}
	inorder(node[c - 65][0].first);
	cout << c;
	inorder(node[c - 65][0].second);
}
void postorder(char c) {
	if (c == '.') {
		return;
	}
	postorder(node[c - 65][0].first);
	postorder(node[c - 65][0].second);
	cout << c;
}
int main(void) {
	init();
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}

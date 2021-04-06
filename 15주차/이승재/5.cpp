// https://www.acmicpc.net/problem/1717
#include <iostream> 
using namespace std;
int board[1000001];

int findroot(int node)
{
	if (node == board[node])
		return node;
	board[node] = findroot(board[node]);
	return board[node];
}


void setroot(int nodeA, int nodeB)
{
	int rootA = findroot(nodeA);
	int rootB = findroot(nodeB);
	board[rootB] = rootA;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; 
	cin >> N >> M;
	for (int i = 0; i < N + 1; i++)
		board[i] = i;

	int num, a, b;
	for (int i = 0; i < M; i++) {
		cin >> num >> a >> b;
		if (num == 0) { // 0이라면 find, 1이라면 print
			setroot(a, b);
		}
		else {
			if (findroot(a) == findroot(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	} 
	return 0;
}

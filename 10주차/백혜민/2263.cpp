#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int in[100001], post[100001];
pair<int, int> tree[100001];

void preorder(int node)
{
	cout << node << " ";
	if (tree[node].first != -1) preorder(tree[node].first);
	if (tree[node].second != -1) preorder(tree[node].second);
}
int makeTree(int ll, int lr, int rl, int rr)
{
	int root = post[lr], idx = find(in, in + N, root) - in, size = idx - rl;
	if (ll == lr) return root;

	if (size > 0) tree[root].first = makeTree(ll, ll + size - 1, rl, rl + size - 1);
	if (ll + size <= lr - 1) tree[root].second = makeTree(ll + size, lr - 1, rl + size + 1, rr);

	return root;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> in[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];

	memset(tree, -1, sizeof(tree));
}
int main()
{
	init();
	makeTree(0, N - 1, 0, N - 1);
	preorder(post[N - 1]);

	return 0;
}

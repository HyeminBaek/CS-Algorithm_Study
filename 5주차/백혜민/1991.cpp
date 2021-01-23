#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[26];
bool visited[26];

void preorder(int x)
{
	cout << static_cast<char>('A' + x);
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]]&&v[x][i]!=-1)
		{
			visited[v[x][i]] = true;
			preorder(v[x][i]);
		}
	}
}
void inorder(int x)
{
	if (v[x].size() >= 1&&v[x][0] != -1) inorder(v[x][0]);
	cout << static_cast<char>('A' + x);
	if (v[x].size() == 2 && v[x][1] != -1) inorder(v[x][1]);
}
void postorder(int x)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]] && v[x][i] != -1)
		{
			visited[v[x][i]] = true;
			postorder(v[x][i]);
		}
	}
	cout << static_cast<char>('A' + x);
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		char a, b, c;	cin >> a >> b >> c;

		if (b == '.') v[a - 'A'].push_back(-1);
		else if(b!='.') v[a - 'A'].push_back(b - 'A');
		if(c!='.')
			v[a - 'A'].push_back(c - 'A');
		else if (c != '.') v[a - 'A'].push_back(c - 'A');
	}
}
int main()
{
	init();
	preorder(0); cout << "\n";
	memset(visited, false, sizeof(visited));
	inorder(0); cout << "\n";
	memset(visited, false, sizeof(visited));
	postorder(0); cout << "\n";

	return 0;
}

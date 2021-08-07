#include <iostream>
#include <vector>
using namespace std;

struct tree
{
	int left = 0;
	int right = 0;
};
tree t[1000001];//왼쪽 자식,오른쪽 자식

void post(int idx)
{
	if (t[idx].left!=0)
		post(t[idx].left);
	if (t[idx].right != 0)
		post(t[idx].right);
	cout << idx << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int root, x; cin >> root;

	while (cin >> x)
	{
		int node = root;

		while (1)
		{
			if (node > x)
			{
				if (t[node].left == 0)
				{
					t[node].left = x;
					break;
				}
				else
					node = t[node].left;
			}
			else
			{
				if (t[node].right==0)
				{
					t[node].right = x;
					break;
				}
				else
					node = t[node].right;
			}
		}
	}
	post(root);

	return 0;
}

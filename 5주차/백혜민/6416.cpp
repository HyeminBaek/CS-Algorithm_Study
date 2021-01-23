#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	map<int, int> p, c;

	bool flag = false;
	int parent = 0; int k = 1;

	while (1)
	{
		int u, v; cin >> u >> v;

		if (u < 0 && v < 0) break;
		else if (u == 0 && v == 0)
		{
			for (int i = 0; i < p.size(); i++)
			{
				if (p[i] == 0) continue;
				if (c.find(i) == c.end()) parent++;
			}
			if (parent != 1) flag = true;

			if (!flag||p.empty()&&c.empty())
				cout << "Case " << k++ << " is a tree.\n";
			else
				cout << "Case " << k++ << " is not a tree.\n";

			p.clear(); c.clear(); flag = false; parent = 0;
		}
		else
		{
			if (u == v) flag = true;
			if (p.empty() || p.find(u) == p.end())
			{
				p.insert({ u, 1 });
			}
			else
				p[u]++; 
			if (c.empty() || c.find(v) == c.end())
				c.insert({ v, 1 });
			else
				flag = true;
		}
	}

	return 0;
}

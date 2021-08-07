#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (N; N > 0; N--)
	{
		char c; cin >> c;
		int K; vector<int> tmp;

		if (c == 'a')
		{
			cin >> K;

			if (v.empty())
			{
				tmp.push_back(K);
				v.push_back(tmp);
			}
			else
			{
				v.push_back(v.back());
				v.back().push_back(K);
			}
		}
		else if (c == 's')
		{
			if (!v.back().empty())
			{
				v.push_back(v.back());
				v.back().pop_back();
			}
		}
		else if (c == 't')
		{
			cin >> K;

			if (!v.empty() && K >= 2)
			{
				v.push_back(v[K - 2]);
			}
			else if (K == 1)
			{
				v.push_back(tmp);
			}
		}

		if (v.empty() || v.back().empty()) cout << "-1\n";
		else cout << v.back().back() << "\n";
	}

	return 0;
}

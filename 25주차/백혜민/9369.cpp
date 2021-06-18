#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;

void sol(string d,string q)
{
	string answer = "";

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].length() != d.length()) continue;

		map<char, char> m, abc;

		bool flag = true;

		for (int j = 0; j < d.length(); j++)
		{
			if (abc.find(v[i][j]) != abc.end())
			{
				if (abc[v[i][j]] != d[j])
				{
					flag = false; break;
				}
			}
			if (m.find(d[j]) != m.end())
			{
				if (m[d[j]] != v[i][j])
				{
					flag = false; break;
				}
			}
			else
			{
				m.insert({ d[j],v[i][j] });
				abc.insert({ v[i][j],d[j] });
			}
		}

		if (flag)
		{
			if (abc.size() == 25)
			{
				int idx = -1, val = -1;
				bool check[26] = { false, };
				for (int i = 0; i < 26; i++)
				{
					if (abc.find('a' + i) != abc.end())
					{
						check[abc['a'+ i]-'a'] = true;
					}
					else idx = i;
				}
				for (int i = 0; i < 26; i++)
				{
					if (!check[i])
					{
						val = i; break;
					}
				}
				abc.insert({ 'a' + idx,'a' + val });
			}
			string tmp = "";
			for (int j = 0; j < q.length(); j++)
			{
				if (abc.find(q[j])==abc.end()) tmp += "?";
				else tmp += abc[q[j]];
			}

			if (answer.empty()) answer = tmp;
			else
			{
				for (int i = 0; i < answer.length(); i++)
				{
					if (answer[i] != tmp[i]) answer[i] = '?';
				}
			}
		}
	}

	if (answer.empty()) cout << "IMPOSSIBLE\n";
	else cout << answer << "\n";
}
void init(string &d,string &q)
{
	int N; cin >> N;

	v.clear();
	for (N; N > 0; N--)
	{
		string s; cin >> s;
		v.push_back(s);
	}

	cin >> d >> q;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (T; T > 0; T--)
	{
		string d = "", q = "";
		init(d, q);
		sol(d, q);
	}
	return 0;
}

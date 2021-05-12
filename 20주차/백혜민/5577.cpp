#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
12:40~
13 3 1 3 3 3 3 2 2 2 1 1 1 3
*/

struct pang //erase..
{
	int color, cnt;
};
int M;
vector<pang> v;

void RBYpang(int idx,int cur)
{
	vector<pang> temp;
	for (int i = 0; i < v.size(); i++)
		temp.push_back(v[i]);

	temp[idx].cnt--; temp[cur].cnt++;

	if (temp[idx].cnt == 0) temp.erase(temp.begin() + idx);

	for (int i = 0; i < temp.size(); i++)
	{
		if (i + 1 < temp.size() && temp[i].color == temp[i + 1].color)
		{
			temp[i].cnt += temp[i + 1].cnt;
			temp.erase(temp.begin() + (i + 1));
		}
		if (temp[i].cnt >= 4)
		{
			temp.erase(temp.begin() + i);
			i-=2;
		}
	}

	int sum = 0;
	for (int i = 0; i < temp.size(); i++)
		sum += temp[i].cnt;

	M = (sum < M) ? sum : M;
}
void find()
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].cnt >= 3)
		{
			if (i > 0) RBYpang(i - 1, i);
			if (i < v.size() - 1) RBYpang(i + 1, i);
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (N; N > 0; N--)
	{
		int x; cin >> x;
		
		if (v.empty())
			v.push_back({ x,1 });
		else
		{
			if (v.back().color == x) v.back().cnt++;
			else v.push_back({ x,1 });
		}
	}

	M = 987654321;
}
int main()
{
	init();
	find();

	cout << M;

	return 0;
}

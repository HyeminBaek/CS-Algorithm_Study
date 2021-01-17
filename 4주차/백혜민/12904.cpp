#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, T; cin >> S >> T;

	vector<char> temp;
	for (int i = 0; i < T.length(); i++)
		temp.push_back(T[i]);

	for (int i = temp.size() - 1; i >= S.length(); i--)
	{
		if (temp[i] == 'A') temp.pop_back();
		else
		{
			temp.pop_back();
			reverse(temp.begin(), temp.end());
		}
	}

	bool flag = true;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != temp[i])
		{
			flag = false; break;
		}
	}

	cout << flag;

	return 0;
}

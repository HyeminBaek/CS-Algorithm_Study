#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, bomb; cin >> s >> bomb;
	char* answer = new char[s.length() + 1];
	int idx = 0;

	for (int i = 0; i < s.length(); i++)
	{
		//cout << i << " " << s.substr(i, bomb.length()) << endl;
		//cout << idx << endl;
		if (answer[idx-1] == bomb[bomb.length() - 1])
		{
			bool tf = false;
			for (int j = 0; j < bomb.length(); j++)
			{
				if (answer[idx-1 - j] != bomb[bomb.length() - 1 - j])
				{
					tf = true; break;
				}
				//cout << answer[idx-1 - j] << " " << bomb[bomb.length() - 1 - j] << endl;
			}
			if (!tf)
			{
				idx -= bomb.length();
			}
		}
		if (s.substr(i, bomb.length()) == bomb)
			i += bomb.length() - 1;
		else
			answer[idx++] = s[i];
	}
	
	string temp = "";
	if (answer[idx - 1] == bomb[bomb.length() - 1])
	{
		for (int i = bomb.length(); i > 0; i--)
		{
			temp += answer[idx - i];
		}
		if (temp == bomb)
			idx -= bomb.length();
	}
	
	if (idx == 0)
		cout << "FRULA";
	else
	{
		for (int i = 0; i < idx; i++)
			cout << answer[i];
	}

	return 0;
}

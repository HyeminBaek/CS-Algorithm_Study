#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	//i번째 인덱스가 i-1번째보다 사전순으로 뒤면 0번째 인덱스로 보냄
	
	for (int i = 1; i < s.length(); i++)
	{
		string temp = "";

		if (s[i] > s[i - 1])
		{
			temp = s[i];

			for (int j = 0; j < s.length(); j++)
			{
				if (i != j)
					temp += s[j];
			}

			s = temp;
		}
	}
	reverse(s.begin(), s.end());
	cout << s;

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool find(string a, string b)
{
	for (int i = 0; i < b.length(); i+=a.length())
	{
		if (i + a.length()<b.length())
		{
			string temp = b.substr(i, a.length());
			if (temp == a)
				return false; //접두어인 경우 false 리턴
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		string* arr = new string[n];
		for (int j = 0; j < n; j++)
			cin >> arr[j];

		sort(arr, arr + n);
		
		bool flag = true;
		for (int j = 0; j < n-1; j++)
		{
            /*
            다른 번호의 접두어임을 확인하기 때문에 다음 전화번호가 더 짧은 경우 
            접두어가 될 수 없으므로 시간초과를 방지하기 위해 아예 확인하지 않는다
            */
			if (arr[j].length() < arr[j+1].length())
			{
				if (!find(arr[j], arr[j+1]))//접두어인 경우
				{
					flag = false; break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

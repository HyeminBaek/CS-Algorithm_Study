#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
문제: 입력으로 주어진 IPv6의 축약되지 않은 형태를 출력
1. 각 그룹의 앞자리의 0의 전체 또는 일부를 생략 할 수 있다.
2. 0으로만 이루어져 있는 그룹 -> 콜론 2개(::)로 바꿀 수 있다.
3. 2는 오직 한 번만 사용할 수 있다.
*/

string s;

void sol()
{
	//0으로만 이루어져 있는 그룹 -> 콜론 2개(::)로 바꿀 수 있다.
	if (s == "::")
	{
		cout << "0000:0000:0000:0000:0000:0000:0000:0000"; return;
	}

	vector<string> answer;
	string temp = ""; int idx = -1; bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':') //: 기준 파싱
		{
			if (!temp.empty())
			{
				while (temp.length() < 4)//0이 생략된 것이므로 채워준다
					temp = "0" + temp;
				answer.push_back(temp);

				temp = "";
			}
			if (s[i + 1] == ':') //2번 등장
			{
				idx = answer.size();
				flag = true;
			}
		}
		else
			temp += s[i];
	}

	if (flag) //생략된 위치에 0000 추가
	{
		while (answer.size() < 7)
			answer.insert(answer.begin() + idx++, "0000");
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ":";
	if (!temp.empty())
	{
		while (temp.length() < 4)
			temp = "0" + temp;
		cout << temp;
	}
	else if (answer.size() < 8)
		cout << "0000";
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
}
int main()
{
	init();
	sol();

	return 0;
}
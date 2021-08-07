#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
1. n==1 인 경우
2. 생일이 같은 사람이 여러명
3. s1==s2 부분에서 return 0
*/
int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; //한 달이 며칠까지 있는지 저장용

int dateDiff(string s1, string s2)
{
	if (s1 == s2)	return -1;
	else
	{
		int dif = 0;

		int mon1 = stoi(s1.substr(0, 2));int day1 = stoi(s1.substr(3, 2));
		int mon2 = stoi(s2.substr(0, 2)); int day2 = stoi(s2.substr(3, 2));

		if (mon1 == mon2 && day2 > day1)
			dif = day2 - day1;
		else
		{
			dif += m[mon1] - day1;

			if (mon2 <= mon1) mon2 += 12;
			for (int j = mon1 + 1; j < mon2; j++)
			{
				if (j > 12) dif += m[j - 12];
				else dif += m[j];
			}
			dif += day2;
		}
		//cout << s1 << " " << s2 << " " << dif << endl;
		return dif;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//for (int i = 0; i < 100; i++)
	//{
		int n; cin >> n;

		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string name, birthdate; cin >> name >> birthdate;
			v.push_back(birthdate);
		}

		sort(v.begin(), v.end());

		string answer = ""; int maxDif = 0;

		bool flag = false;

		if (n >= 2)
		{
			for (int i = 0; i < v.size(); i++)
			{
				int tmp = -1, mon = -1, day = -1;
				if (i == v.size() - 1)
				{
					tmp = dateDiff(v[i], v[0]);
					mon = stoi(v[0].substr(0, 2)), day = stoi(v[0].substr(3, 2));
				}
				else
				{
					tmp = dateDiff(v[i], v[i + 1]);
					mon = stoi(v[i + 1].substr(0, 2)), day = stoi(v[i + 1].substr(3, 2));
				}

				if (maxDif <= tmp) //맥스 값 갱신
				{
					string temp = "";

					if (day != 1)
					{
						//월 저장
						if (i + 1 < v.size())
							temp = v[i + 1].substr(0, 3);
						else temp = v[0].substr(0, 3);

						//일 저장
						if (day - 1 > 9) temp += to_string(day - 1);
						else temp += "0" + to_string(day - 1);
					}
					else //1일인 경우 전날이 28,30,31일이 되어야 함
					{
						if (mon != 1)
						{
							if (mon - 1 < 10)
								temp = "0";
							temp += to_string(mon - 1) + "-" + to_string(m[mon - 1]);
						}
						else//1월 1일
							temp = "12-31";
					}

					if (maxDif == tmp)//the date that is soonest after the current date, the 27th of October
					{
						int dif1 = dateDiff("10-27", answer), dif2 = dateDiff("10-27", temp);
						if (dif1 == -1 || (dif1 >= 1 && dif2 < dif1))
							answer = temp;
					}
					else
					{
						maxDif = tmp; answer = temp;
					}
				}
			}
			if (maxDif == 0) flag = true; //만약 2 a 01-01 b 01-01인 경우
		}
		if (n == 1 || flag)
		{
			string temp = "";

			int mon = stoi(v[0].substr(0, 2)), day = stoi(v[0].substr(3, 2));

			if (day != 1)
			{
				if (mon > 9) temp += to_string(mon);
				else temp += "0" + to_string(mon);

				temp += "-";

				if (day - 1 > 9) temp += to_string(day - 1);
				else temp += "0" + to_string(day - 1);
			}
			else //1일인 경우 전날이 28,30,31일이 되어야 함
			{
				if (mon != 1)
				{
					if (mon - 1 < 10)
						temp = "0";
					temp += to_string(mon - 1) + "-" + to_string(m[mon - 1]);
				}
				else//1월 1일
					temp = "12-31";
			}
			answer = temp;
		}

		cout << answer<<endl;
	//}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

priority_queue<pair<string, string>, vector< pair<string, string>>, greater< pair<string, string>>> pq;
priority_queue<pair<string, int>, vector< pair<string, int>>, greater< pair<string, int>>> ht;

void sol()
{
	int cur = 1;

	ht.push({ pq.top().second,cur++ });
	pq.pop();

	priority_queue<int, vector<int>, greater<int>> r;

	while (!pq.empty())
	{
		string std = pq.top().first, edd = pq.top().second;
		pq.pop();

		while (!ht.empty())
		{
			string out = ht.top().first; int num = ht.top().second;

			if (out <= std)
			{
				r.push(num);
				ht.pop();
			}
			else break;
		}

		if (r.empty())
		{
			ht.push({ edd,cur++ });
		}
		else
		{
			ht.push({ edd,r.top() });
			r.pop();
		}
	}

	cout << cur - 1 << "\n";
}
void init(int B,int C)
{
	while (!pq.empty()) pq.pop();
	while (!ht.empty()) ht.pop();

	for (int i = 0; i < B; i++)
	{
		string id, ind, intm, outd, outt;
		cin >> id >> ind >> intm >> outd >> outt;

		int hour= stoi(outt.substr(0,2)), minute= stoi(outt.substr(3,2));
		hour += C / 60; minute += C % 60;

		if (minute >= 60)
		{
			hour++; minute -= 60;
		}

		bool flag = false;
		if (hour >= 24)
		{
			flag = true; hour -= 24;
		}
		string tsh = "", tsm = "";
		if (hour >= 10) tsh = to_string(hour);
		else tsh = "0" + to_string(hour);

		if (minute >= 10) tsm = to_string(minute);
		else tsm = "0" + to_string(minute);

		outt = tsh + ":" + tsm;

		if (flag)
		{
			int year = stoi(outd.substr(0,4)), month = stoi(outd.substr(5, 2)), day = stoi(outd.substr(8, 2));

			day++;

			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day > 31)
				{
					month++; day -= 31;
				}
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 30)
				{
					month++; day -= 30;
				}
			}
			else//16년 윤년
			{
				if (year == 2016)
				{
					if (day > 29)
					{
						month++; day -= 29;
					}
				}
				else
				{
					if (day > 28)
					{
						month++; day -= 28;
					}
				}
			}
			if (month > 12)
			{
				year++; month -= 12;
			}

			string tsy = "", tsd = ""; tsm = "";
			if (year >= 10) tsy = to_string(year);
			else tsy = "0" + to_string(year);

			if (month >= 10) tsm = to_string(month);
			else tsm = "0" + to_string(month);

			if (day >= 10) tsd = to_string(day);
			else tsd = "0" + to_string(day);

			outd = tsy + "-" + tsm + "-" + tsd;
		}
		
		pq.push({ ind + " " + intm, outd + " " + outt });
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (T; T > 0; T--)
	{
		int B, C; cin >> B >> C;

		init(B,C);
		sol();
	}

	return 0;
}

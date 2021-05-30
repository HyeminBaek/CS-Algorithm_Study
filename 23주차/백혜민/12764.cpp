#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;

map<int, int> m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, sg; //시작,끝 끝,num

void sol()
{
	int cur = 1; //지금까지 컴퓨터가 몇 대 필요했는지

	sg.push({ pq.top().second,cur });
	pq.pop(); m.insert({ cur++, 1 });

	priority_queue<int, vector<int>, greater<int>> com; //빈 자리 용

	while (!pq.empty())
	{
		int st = pq.top().first, ed = pq.top().second;
		pq.pop();

		while (!sg.empty()) //끝난 사람을 빈 자리 pq에 넣는다
		{
			int edt = sg.top().first, num = sg.top().second;

			if (edt <= st)
			{
				com.push(sg.top().second);
				sg.pop();
			}
			else break;
		}

		if (com.empty()) //빈 자리가 없으면
		{
			sg.push({ ed,cur }); //새 컴퓨터 추가
			m.insert({ cur++, 1 });
		}
		else //있으면
		{
			sg.push({ ed,com.top() }); //빈 자리에 사람 추가
			m[com.top()]++; //빈도수 세기
			com.pop(); 
		}
	}
	cout << cur - 1 << "\n";

	for (int i = 1; i < cur; i++)
		cout << m[i] << " ";
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (N; N > 0; N--)
	{
		int P, Q; cin >> P >> Q;
		pq.push({ P,Q });
	}
}
int main()
{
	init();
	sol();

	return 0;
}

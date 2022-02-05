#include <iostream>
#include <vector>
#include <limits>
using namespace std;

/*
* 문제 요구사항: 용사가 N번 방에 있는 용을 쓰러트리기 위한 최소의 HMaxHP
*/

/* basic global var setting */
struct monster
{
	long long atk, hp;
};
struct warrior
{
	long long curHP, maxHP, ATK;
};
struct room
{
	long long type, a, h;
};
long long ans;
warrior w;
vector<room> v;

/* function declarations */
void init();
bool battle(long long curHP);
void sol();

/* logic start */
int main()
{
	init();
	sol();

	return 0;
}
void sol() //이분탐색을 하면서 최소 maxHP를 찾기 위한 함수
{
	long long low = 1, high = 1e18;

	while (low <= high)
	{
		long long mid = (low + high) / 2;

		bool res = battle(mid);

		if (res)
		{
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}

	cout << ans;
}
bool battle(long long curHP) //용사의 N번방까지의 전투를 구현한 함수
{
	warrior tmp = w; tmp.curHP = curHP; tmp.maxHP = curHP;
	
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].type == 1) //몬스터
		{
			monster m = { v[i].a,v[i].h };
			
			long long cnt = (m.hp % tmp.ATK == 0) ? m.hp / tmp.ATK - 1 : m.hp / tmp.ATK;
			tmp.curHP -= cnt * m.atk;

			if (tmp.curHP <= 0) return false;
		}
		else //포션
		{
			tmp.curHP += v[i].h;
			if (tmp.curHP > tmp.maxHP) tmp.curHP = tmp.maxHP;

			tmp.ATK += v[i].a;
			//if (tmp.ATK > 1000000) tmp.ATK = 1000000;
		}
	}
	return true;
}
void init() //입력을 위한 함수
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N >> w.ATK;
	
	/* Input */
	for (int i = 0; i < N; i++)
	{
		int t, a, h; cin >> t >> a >> h;
		v.push_back({ t,a,h });
	}
}

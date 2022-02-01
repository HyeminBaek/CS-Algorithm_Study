#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
양방향 그래프가 주어짐 -> 모든 노드를 "최소 비용"으로 연결해야 함 //MST구나!

∵ MST 조건) 무향 연결그래프, 트리의 가중치가 있다

문제 요구 조건: 모든 건물이 도로를 통해 연결되도록 최소한의 도로를 만들려고 한다.
문제 해결 방법: MST를 구축하면 바로 해결, 전체 가중치에 MST 구축 비용을 빼준다
*/

struct edge
{
	int cur, next, value;
};
int N, M;
long long total;
int parent[100001];
vector<edge> v;

bool comp(edge e1, edge e2) //struct edge를 정렬하기 위한 함수
{
	return e1.value < e2.value;
}
int find(int a) //union-find의 find
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}
bool doUnion(int a, int b) //union-find의 union
{
	a = find(a);
	b = find(b);

	if (a == b) return false;
	else parent[b] = a;

	return true;
}
long long makeTree()
{
	long long res = 0, cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (doUnion(v[i].cur, v[i].next))
		{
			res += v[i].value;

			if (++cnt == N - 1) break;
		}
	}
	if (cnt != N - 1) return total + 1;
	return res;
}
void sol() //문제 해결 함수
{
	cout << total - makeTree();
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/* basic i/o */
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int cur, next, val;
		cin >> cur >> next >> val;

		v.push_back({ cur, next, val });

		total += val;
	}

	sort(v.begin(), v.end(), comp);
	for (int i = 1; i <= N; i++) parent[i] = i;
}
int main()
{
	init();
	sol();

	return 0;
}
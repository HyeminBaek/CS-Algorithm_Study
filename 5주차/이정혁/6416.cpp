#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<pair<int,int>> v;
set<int> s;

/*
1. set의 갯수와 vector의 갯수의 차이는 1개 여야한다. 즉 노드의 수와 간선의 수 차이는 1 이어야 한다.
2. 노드의 갯수가 0개인 것도 트리이다.


배운점
------- set의 사용 : set은 value가 키 값으로 들어가며 중복 될 수 없다.

*/

int main(void) {
	int tc = 1;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a < 0 && b < 0) {
			break;
		}
		if (a == 0 && b == 0) {
			if (s.size() - v.size() == 1) {
				cout << "Case " << tc << " is a tree." << '\n';
			}
			else if (v.size() == 0) { //****** 노드의 갯수가 0이어도 트리이다..
				cout << "Case " << tc << " is a tree." << '\n';
			}
			else {
				cout << "Case " << tc << " is not a tree." << '\n';
			}
			s.clear();
			v.clear();
			tc++;
		}
		else {
			s.insert(a);
			s.insert(b);
			v.push_back({ a,b });
		}
	}
	return 0;
	
}

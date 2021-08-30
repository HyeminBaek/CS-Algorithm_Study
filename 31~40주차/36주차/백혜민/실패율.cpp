#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair 
{
	double d; int i;

};
bool compare(Pair& p1, Pair& p2) 
{
	if (p1.d == p2.d) return p1.i<p2.i;
	return p2.d < p1.d;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	map<int, int> m;
	for (int i = 1; i <= N + 1; i++) m.insert({ i,0 });
	for (int i = 0; i < stages.size(); i++) m[stages[i]]++;
	
	vector<Pair> v;
	for (int i = 1; i <= N; i++) {
		double cnt = 0;
		for (int j = i; j <= N + 1; j++) cnt += m[j];
		
		if (cnt != 0) cnt = (double)(m[i]) / cnt;
		v.push_back({ cnt,i });
	}

	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < v.size(); i++) answer.push_back(v[i].i);

	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
	return answer;
}
/*
2021/08/16 14:12 

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Vertex {
	int pop;
	vector<int> adjlist;
};
int N,n,k,check[10],globalsum,visit[10],ct;
Vertex v[10];
int search();
int BFS(int bit);
int ABS(int a);
int main() {
	scanf("%d", &N);
	globalsum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i].pop);
		visit[i] = -1;
		globalsum += v[i].pop;
	}
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &k);
			
			v[i].adjlist.push_back(k - 1);
		}
	}
	printf("%d\n", search());



	return 0;
}
int ABS(int a) {
	return a < 0 ? -a : a;
}
int search() {
	int ret = -1;
	ct = 0;
	
	for (int i = 1; i < (1<<N)-1; i++) {
		ct++;
		int r = BFS(i);
		if (r == -1) continue;
		if (ret == -1) {
			ret = r;
		}
		else {
			ret = min(r, ret);
		}
	}

	return ret;
}
int BFS(int bit) {
	queue<int> q;
	int sum0 = 0, sum1 = 0;
	for (int i = 0; i < N; i++) {
		if (((1 << i) & bit) == 0) { // 0
			q.push(i);
			visit[i] = ct;
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				sum0 += v[t].pop;

				for (int j = 0; j < v[t].adjlist.size(); j++) {
					int next = v[t].adjlist[j];
					if (visit[next]!=ct && ((1 << next) & bit) == 0) {
						visit[next] = ct;
						q.push(next);
					}

				}


			}



			break;
		}

	}

	for (int i = 0; i < N; i++) {
		if (((1 << i) & bit) != 0) { // 1
			q.push(i);
			visit[i] = ct;
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				sum1 += v[t].pop;

				for (int j = 0; j < v[t].adjlist.size(); j++) {
					int next = v[t].adjlist[j];
					if (visit[next] != ct && ((1 << next) & bit) != 0) {
						visit[next] = ct;
						q.push(next);
					}

				}


			}


			break;
		}

	}
	if (sum0 + sum1 != globalsum) return -1;
	return ABS(sum0 - sum1);


}
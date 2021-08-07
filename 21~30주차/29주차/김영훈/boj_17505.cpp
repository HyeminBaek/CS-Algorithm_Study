/*
  어떤수 n을 놓을 때
  부분수열 A1,A2,A3, ... ,A(n-1)
  부분수열의 수는 n보다 모두 작음
  n을 어디에 껴놓는가에 따라 반전개수가 0~n-1개까지 증가시킬 수 있음
  그리디하게 최댓값만 취하고 난 뒤 남은 갯수만큼 취함

  수열저장하는 법
  최댓값만 취하므로 순서는 n, n-1 ,n-2 ,n-3 ...(n+1)., 1 , n+2, n+3, ... , N
  이때 K보다 n+1이 작은 경우(사이에 껴놓는 경우)만 고려 나머지는 0개
*/



#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll N, K;
vector<ll> ans;
int main() {
	scanf("%lld%lld", &N, &K);
	ans.clear();
	for (ll i = 0; i < N; i++) {
		if (K > i) {
			K -=i;
		}
		else {	
			for (ll j = i-1; j >= K; j--) {
				ans.push_back(j + 1);
			}
			ans.push_back(i+1);
			for (ll j = K-1; j>=0; j--) {
				ans.push_back(j + 1);
			}
			for (ll j = i + 1; j < N; j++) {
				ans.push_back(j+1);
			}
			K = 0;
			break;
		}
	}
	if (K > 0) {
		printf("-1");
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			printf("%lld ", ans[i]);
		}
	}
	printf("\n");
	return 0;
}
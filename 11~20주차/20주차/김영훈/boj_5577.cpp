#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 10001;
int N, arr[10000],arr_copy[10000];
int Pang(int pos) {
	int ret = N;
	int idx1 = pos;
	int idx2 = pos+1;
	int ncolor[2]={ 0,0 }, ct[2] = { 0,0 };
	while (1) {		
		if (idx1>=0 &&ct[0] == 0) {
			ncolor[0] = arr_copy[idx1];
			while (idx1 >= 0 && arr_copy[idx1] == ncolor[0]) {
				idx1--;
				ct[0]++;
			}
		}
		if (idx2<N && ct[1] == 0) {
			ncolor[1] = arr_copy[idx2];
			while (idx2 < N && arr_copy[idx2] == ncolor[1]) {
				idx2++;
				ct[1]++;
			}
		}
		if (ncolor[0] == ncolor[1]) {
			int sum = ct[0] + ct[1];
			if (sum < 4) {
				break;
			}
			ret -= sum;
			ncolor[0] = 0;
			ncolor[1] = 0;
			ct[0] = 0;
			ct[1] = 0;
		}
		else {
			if (ct[0] < 4 && ct[1] < 4) {
				break;
			}
			if (ct[0] >= 4) {
				ret -= ct[0];
				ct[0] = 0;
				ncolor[0] = 0;
			}
			if (ct[1] >= 4) {
				ret -= ct[1];
				ct[1] = 0;
				ncolor[1] = 0;
			}
		}

		

	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int answer = N;
	for (int i = 0; i < N; i++) {
		
			for (int j = 0; j < N; j++) {
				arr_copy[j] = arr[j];
			}
			arr_copy[i] = (arr[i]) % 3 + 1;
			answer = min(Pang(i), answer);
		
			for (int j = 0; j < N; j++) {
				arr_copy[j] = arr[j];
			}
			arr_copy[i] = (2 + arr[i] - 1) % 3 + 1;
			answer = min(Pang(i), answer);
			
	}
	printf("%d\n", answer);
	return 0;
}
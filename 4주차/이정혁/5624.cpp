#include<iostream>
#include<vector>

using namespace std;

/*
D = A + B + C 로 나타낼 수 있다.
마찬가지로 D - C = A + B 로 나타낼 수 있다.
그러므로 visited[A + B] == true 이면 visited[D - C] = true 이므로 result ++ 해준다.
*/
int N, result;
vector<int> num;
bool visited[400001];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.emplace_back(n);
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) { // 아래에서 A + B 반환 시켜준 곳이랑 D - C 값이랑 같으니까 true 면은 result ++
			if (visited[num[i] - num[j] + 200000]) {
				result++;
				break;
			}
		}
		for (int j = 0; j <= i; j++) { // A + B 가 가능한 숫자에 true
			visited[num[i] + num[j] + 200000] = true;
		}
	}
}

int main(void) {
	init();
	solution();
	cout << result;
	return 0;
}

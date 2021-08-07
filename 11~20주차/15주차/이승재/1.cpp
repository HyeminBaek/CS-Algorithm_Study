//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <climits>
using namespace std;
int arr[5] = { 0, 0, 0, 0, 0 };
int* numbers;
int answer_max = INT_MIN;
int answer_min = INT_MAX;

void dfs(int idx, int total_sum) {
	if (idx == arr[4]) {
		answer_max = max(answer_max, total_sum);
		answer_min = min(answer_min, total_sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i] == 0)
			continue;
		arr[i] -= 1;
		if (i == 0)
			dfs(idx + 1, total_sum + numbers[idx]);
		else if (i == 1)
			dfs(idx + 1, total_sum - numbers[idx]);
		else if (i == 2)
			dfs(idx + 1, total_sum * numbers[idx]);
		else if (i == 3)
			dfs(idx + 1, int(total_sum / numbers[idx]));
		arr[i] += 1;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	numbers = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	arr[4] = num;
	dfs(1, numbers[0]);
	delete[]numbers;
	
	cout << answer_max << "\n";
	cout << answer_min << "\n";
	return 0;
}

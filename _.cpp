#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, budget;
int cost[10];
vector<int> dp[51];

bool compare(int b, vector<int> first, vector<int> second) {
    //마지막에 한 번만 확인) 어느 한 쪽의 모든 원소가 0이라면 폐기
    if (b == budget) {
        if (first.size() > 0 && first[first.size() - 1] == 0) return 0;
        if (second.size() > 0 && second[second.size() - 1] == 0) return 1;
    }

    //정렬되어 input으로 들어오는 두 vector를 비교해 큰 쪽을 알려줌 (0 : first, 1 : second)
    if (first.size() > second.size()) {
        //if (first[first.size() - 1] == 0) return 0;
        return 1;
    }
    if (first.size() < second.size()) {
        //if (second[second.size() - 1] == 0) return 1;
        return 0;
    }

    //사이즈가 같은 경우 제일 오른쪽 원소의 값을 비교
    int end = first.size() - 1;
    for (int i = end; i >= 0; i--) {
        if (first[i] > second[i]) return 1;
        if (first[i] < second[i]) return 0;
    }
    //같은 수일 경우 아무거나 반환
    return 0;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cin >> budget;

    for (int i = 1; i <= budget; i++) {
        for (int j = 0; j < n; j++) {
            //i원을 가지고 있는 상태에서 0 ~ n-1 숫자들을 각각 구매했을 때 비용을 비교한다.
            //1. 가격이 낮은 숫자를 우선으로 구매한다.
            //2. 같은 가격이면 높은 숫자를 구매한다.

            //현재 금액으로 숫자를 살 수 없는 경우
            if (i < cost[j]) continue; // 숫자 못 사는 경우

            //현재 숫자(j)를 구매한 상태의 vector가 저장된 vector보다 크다면 교체
            vector<int> temp = dp[i - cost[j]];
            sort(temp.begin(), temp.end());
            temp.push_back(j);
            if (compare(i, temp, dp[i])) dp[i] = temp;
        }
        //현재 금액에서 아무것도 사지 않았을 경우를 체크
        if (compare(i, dp[i - 1], dp[i])) dp[i] = dp[i - 1];
    }

    if (dp[budget].empty()) dp[budget].push_back(0);
    for (int i = dp[budget].size() - 1; i >= 0; i--) {
        cout << dp[budget][i];
    }

    return 0;
}
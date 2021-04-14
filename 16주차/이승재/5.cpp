//https://www.acmicpc.net/problem/14863
#include <iostream>
using namespace std;

int main() {
    static int arr[101][100001];

    int N, K;
    cin >> N >> K;
    int walk_time, walk_cost, cycle_time, cycle_cost;
    cin >> walk_time >> walk_cost >> cycle_time >> cycle_cost;

    /*
     * 초기값 설정. i = 0일 때는 0 이므로 i = 1일 때부터 시작
     */
    arr[1][walk_time] = walk_cost;
    arr[1][cycle_time] = max(arr[1][cycle_time], cycle_cost);

    for (int i = 2; i <= N; i++) {
        cin >> walk_time >> walk_cost >> cycle_time >> cycle_cost;
        for (int j = 0; j <= K; j++) {
            if (arr[i - 1][j] != 0) {
                /*
                 * 이전 시도를 방문하지 않은 경우 pass
                 * 소요시간 + 현재 시간이 최대 시간보다 짧은경우,
                 * 새로운 시간 vs 이전시간 + cost
                 */
                if (j + walk_time <= K) // walk
                    arr[i][j + walk_time] = max(arr[i][j + walk_time], arr[i - 1][j] + walk_cost);
                if (j + cycle_time <= K) // cycle
                    arr[i][j + cycle_time] = max(arr[i][j + cycle_time], arr[i - 1][j] + cycle_cost);
            }
        }
    }
    int answer = -1;
    for (int i = 0; i <= K; i++)
        answer = max(answer, arr[N][i]); // 시간마다 가장 높은 cost는 모든 도시를 거쳐간 마지막 행일때
    cout << answer;
    return 0;
}

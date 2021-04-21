#include <iostream>
using namespace std;

int n, m;  // 소세지100 사람100

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 최대 <사람 수-1> 만큼 자르면 소세지수가 된다
// 이미 소세지가 n개로 나눠져있으면 gcd(n,m)만큼 덜 자른다
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cout << m - gcd(n, m);

    return 0;
}

#include <iostream>

using namespace std;

int solve() {
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cout << '#' << test_case << ' ' << solve() << '\n';
    }
    return 0;
}
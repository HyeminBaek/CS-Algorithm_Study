#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int L, K, C;
vector<int> points;

bool canBuild(int thr, int pos) {
    int count = 1;
    for(int i = 0; i < K; i++) {
        if(pos + thr >= L) break;
        if(i == 0 && points[i] > pos+thr) {
            return 0;
        }
        if(points[i] == pos+thr) {
            pos = points[i];
            count += 1;
            if(points[i] > pos + thr) return 0;
        }
        else if(points[i] > pos+thr) {

            pos = points[i-1];
            count += 1;
            if(points[i] > pos + thr) return 0;
        }

    }
    if(pos + thr >= L) {
        return count <= C;
    } else {
        pos = points[K-1];
        count += 1;
        return pos+thr >= L && count <= C;
    }
}

int check(int thr) {
    int count = 0;
    int pos = 0;
    for(int i = 0; i < K; i++) {
        if(pos + thr >= L) break;
        if(i == 0 && points[i] > pos+thr) {
            return 0;
        }
        if(points[i] == pos+thr) {
            pos = points[i];
            count += 1;
            if(points[i] > pos + thr) return 0;
        }
        else if(points[i] > pos+thr) {

            pos = points[i-1];
            count += 1;
            if(points[i] > pos + thr) return 0;
        }

    }
    if(pos + thr >= L) {
        return count <= C;
    } else {
        pos = points[K-1];
        count += 1;
        return pos+thr >= L && count <= C;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> K >> C;
    points.resize(K);
    for(auto &it: points) cin >> it;
    sort(points.begin(), points.end());
    int lo = 0, hi = 1e9+1;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    bool found = false;
    for(int i = 0; i < K; i++) {
        found = canBuild(hi, points[i]);
        if(found) {
            cout << hi << " " << points[i] << "\n";
            return 0;
        }
    }
}

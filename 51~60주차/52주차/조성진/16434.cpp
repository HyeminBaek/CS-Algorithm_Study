#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct room_info {
    ll isMonster;
    ll attack;
    ll hp;
};
ll N, ATK;
room_info rooms[123456];
bool clearRoom(int idx, ll max_hp, ll& hp, ll& atk) {
    if(rooms[idx].isMonster == 1) {
        ll adder = (rooms[idx].hp % atk == 0 ? 0 : 1);
        ll my_atk_cnts = rooms[idx].hp / atk + adder;
        hp -= rooms[idx].attack * (my_atk_cnts-1);
        if(hp <= 0) return false;
    } else {
        atk += rooms[idx].attack;
        hp = min(max_hp, hp+rooms[idx].hp);
    }
    return true;
}
bool check(ll thr) {
    ll cur_hp = thr, cur_atk = ATK;
    for(int i = 0; i < N; i++) {
        if(!clearRoom(i, thr, cur_hp, cur_atk)) return false;
    }
    return true;
}
int main() {
    cin >> N >> ATK;
    for(int i = 0; i < N; i++) {
        ll i1, i2, i3; cin >> i1 >> i2 >> i3;
        rooms[i] = {i1, i2, i3};
    }
    ll lo = -1, hi = LLONG_MAX;
    while(lo+1 < hi) {
        ll mid = (lo+hi) >> 1;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";


}
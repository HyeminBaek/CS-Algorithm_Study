#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _INFO{
    string name;
    int month;
    int day;
} INFO;

int m_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daysOfMonth[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};  // 해당 월까지 날짜의 누적 합
int step[100];
vector<INFO> person;

// 이름 무시, 월,일을 기준으로 정렬
bool cmp(INFO a, INFO b){
    int t_a = (daysOfMonth[a.month-1]+a.day >= 302) ? a.month : a.month+12;
    int t_b = (daysOfMonth[b.month-1]+b.day >= 302) ? b.month : b.month+12;

    if(t_a == t_b){
        return a.day < b.day;
    }
    return t_a < t_b;
}

// 이전 날짜에서 현재 날짜까지의 총일 계산해주는 함수
int calcu(INFO prev, INFO next){
    int month = prev.month;
    int day = m_day[month] - prev.day;

    //(4, 4) 인 경우
    if(month == next.month){
        return day;
    }
    while(1){
        month = 12 < month+1 ? 1 : month+1;
        if(month == next.month){
            break;
        }
        day += m_day[month];
    }
    day += next.day;

    return day;
}

// 월, 일을 string으로 바꿔서 출력해주는 함수
void Print(int m, int d){
    string ans = "";
    if(m < 10){
        ans += "0";
    }
    ans += (to_string(m)+"-");
    if(d < 10){
        ans += "0";
    }
    ans += to_string(d);

    cout << ans << "\n";
}

int getGap(INFO c1, INFO c2){
    int dayOfc1 = daysOfMonth[c1.month-1]+c1.day;
    int dayOfc2 = daysOfMonth[c2.month-1]+c2.day;

    if(dayOfc1 <= dayOfc2)
        return dayOfc2 - dayOfc1;
    else
        return (366- dayOfc1 + dayOfc2);
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        string s, d;
        cin >> s >> d;

        person.push_back({s, stoi(d.substr(0, 2)), stoi(d.substr(3, 2))});        
    }

    sort(person.begin(), person.end(), cmp);
    int Max = getGap(person[n-1], person[0]);
    INFO ans = person[0];
    for(int i=1; i<n; i++){
        int temp = getGap(person[i-1], person[0]);
        if(Max < temp){
            Max = temp;
            ans = person[i];
        }
    }

    if(ans.day == 1){
        int m_ans = ans.month-1 < 1 ? 12 : ans.month-1;
        int d_ans = m_day[m_ans];
        Print(m_ans, d_ans);
    }
    else{
        Print(ans.month, ans.day-1);
    }


#if 0
    int Max = 0;
    for(int i=0; i<n; i++){
        if(i == 0){
            step[i] = calcu(person[n-1], person[i]);
        }
        else{
            step[i] = calcu(person[i-1], person[i]);
        }
        Max = max(Max, step[i]);
    }

    int idx = 0;
    for(int i=0; i<n; i++){
        if(Max == step[i]){
            idx = i;
            break;
        }
    }

    if(person[idx].day == 1){
        int m_ans = person[idx].month-1 < 1 ? 12 : person[idx].month-1;
        int d_ans = m_day[m_ans];
        Print(m_ans, d_ans);
    }
    else{
        Print(person[idx].month, person[idx].day-1);
    }
#endif
    return 0;
} 
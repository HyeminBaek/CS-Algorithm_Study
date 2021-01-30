//
//  main.cpp
//  Birthday Boy
//
//  Created by 오현식 on 2021/01/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct colleague
{
    string name;
    int month, day;
    
    colleague(string name, string birthday)
    {
        this->name=name;
        month = stoi(birthday.substr(0,2));
        day = stoi(birthday.substr(3,2));
    }
};

int n;
int maximumGap;
vector<colleague>   colleagues;
int dayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 해당 월의 날수
int daysOfMonth[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};  // 해당 월까지 날짜의 누적 합

int getGap(const colleague &c1, const colleague &c2)
{
    int dayOfC1 = daysOfMonth[c1.month-1]+c1.day;
    int dayOfC2 = daysOfMonth[c2.month-1]+c2.day;
    if(dayOfC1<=dayOfC2)   return (dayOfC2-dayOfC1+1);
    else    return (366-dayOfC1+dayOfC2);
}

bool compare(const colleague &c1, const colleague &c2)  //  10/29 ~ 10/28 순으로 정렬
{
    int monthOfC1 = (daysOfMonth[c1.month-1]+c1.day>=302) ? c1.month : c1.month+12;
    int monthOfC2 = (daysOfMonth[c2.month-1]+c2.day>=302) ? c2.month : c2.month+12;
    
    if(monthOfC1==monthOfC2)    return c1.day<c2.day;
    else    return monthOfC1<monthOfC2;
}

string getBirthday(const colleague &c)
{
    string monthOfBirthday, dayOfBirthday;
    int month = c.month;
    int day = c.day;
    if(month==1&&day==1)    return "12-31";
    if(day-1==0)
    {
        month-=1;
        day = dayOfMonth[month];
    }
    else    day-=1;
    monthOfBirthday = to_string(month);
    if(monthOfBirthday.length()==1) monthOfBirthday="0"+monthOfBirthday;
    dayOfBirthday = to_string(day);
    if(dayOfBirthday.length()==1)   dayOfBirthday="0"+dayOfBirthday;
    return monthOfBirthday+"-"+dayOfBirthday;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    string name, birthday;
    string ans;
    colleague answer("","00-00");
    for(int i=0;i<n;i++)
    {
        cin>>name>>birthday;
        colleague colleagueOfMine(name,birthday);
        colleagues.push_back(colleagueOfMine);
    }
    sort(colleagues.begin(),colleagues.end(),compare);
    maximumGap = getGap(colleagues[colleagues.size()-1],colleagues[0]);
    answer = colleagues[0];
    //cout<<colleagues[colleagues.size()-1].month<<"-"<<colleagues[colleagues.size()-1].day<<","<<colleagues[0].month<<"-"<<colleagues[0].day<<" "<<maximumGap<<endl;//
    for(int i=1;i<colleagues.size();i++)
    {
        int gap =  getGap(colleagues[i-1],colleagues[i]);
        //cout<<colleagues[i-1].month<<"-"<<colleagues[i-1].day<<","<<colleagues[i].month<<"-"<<colleagues[i].day<<" "<<gap<<endl;//
        if(gap>maximumGap)
        {
            maximumGap = gap;
            answer = colleagues[i];
        }
    }
    ans = getBirthday(answer);
    cout<<ans;
    return 0;
}

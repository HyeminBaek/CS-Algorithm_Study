//
//  main.cpp
//  선 긋기
//
//  Created by 오현식 on 2021/01/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>>   lines;

bool compare(pair<int,int> line1, pair<int,int> line2)
{
    if(line1.first<line2.first) return true;
    else    return false;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y;
    int low, high;
    int answer = 0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        lines.push_back(make_pair(x,y));
    }
    sort(lines.begin(),lines.end(),compare);
    low = lines[0].first;
    high = lines[0].second;
    
    for(int i=1;i<lines.size();i++)
    {
        if(lines[i].first>high)
        {
            answer += (high-low);
            low = lines[i].first;
            high = lines[i].second;
        }
        else
        {
            high = max(high,lines[i].second);
        }
    }
    answer += (high-low);
    cout<<answer;
    return 0;
}

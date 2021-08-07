//
//  main.cpp
//  개똥벌레
//
//  Created by 오현식 on 2021/01/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, H;
int minimumNumOfObstacles=INT_MAX;
int cntOfPath;
vector<int> stonesUpper;
vector<int> stonesUnder;

int l_bound(vector<int> &stones, int posOfFireFly)
{
    int first, mid, last;
    first = 0;
    last = (int)stones.size();
    while(first<last)
    {
        mid = (first+last)/2;
        if(stones[mid]>=posOfFireFly)    last = mid;
        else if(stones[mid]<posOfFireFly)   first = mid+1;
    }
    return last;
}

int main(int argc, const char * argv[]) {
    int stone;
    cin>>N>>H;
    for(int i=0;i<N;i++)
    {
        cin>>stone;
        if(i%2==0)  stonesUnder.push_back(stone);
        else    stonesUpper.push_back(stone);
    }
    sort(stonesUpper.begin(),stonesUpper.end());
    sort(stonesUnder.begin(),stonesUnder.end());
    for(int h=1;h<=H;h++)
    {
        int numOfObstacles = (int)stonesUnder.size()-l_bound(stonesUnder,h);
        numOfObstacles += (int)stonesUnder.size()-l_bound(stonesUpper,H+1-h);
        if(numOfObstacles<minimumNumOfObstacles)
        {
            cntOfPath=1;
            minimumNumOfObstacles = numOfObstacles;
        }
        else if(numOfObstacles==minimumNumOfObstacles)    cntOfPath++;
    }
    cout<<minimumNumOfObstacles<<" "<<cntOfPath;
    return 0;
}

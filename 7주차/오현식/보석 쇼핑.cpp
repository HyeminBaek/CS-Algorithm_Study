#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> set(gems.begin(),gems.end());
    int sz=set.size();
    int s=0, l=1;
    int length=9999999;
    map<string,int> m;
    m[gems[0]]++;
    for(;s<gems.size();s++)
    {
        while(m.size()!=sz && l<gems.size())    m[gems[l++]]++;
        if(m.size()!=sz && l==gems.size())  break;
        if(length>l-s)
        {
            length=l-s;
            answer = {s+1,l};
        }
        if(m[gems[s]]==1)  m.erase(gems[s]);
        else    m[gems[s]]--;
    }
    return answer;
}

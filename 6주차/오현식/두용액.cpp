//
//  main.cpp
//  두 용액
//
//  Created by 오현식 on 2021/01/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct solution
{
    bool acid;
    int num;
    solution(bool a=false, int n=0):acid(a),num(n){}
};

int N;
vector<solution>    solutions;

bool compare(solution s1, solution s2)
{
    if(s1.num<s2.num)   return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    int num;
    int minimumGap=INT_MAX;
    int answer=-1;
    bool check=true;
    solution s;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        if(num<0) s.acid = true;
        else s.acid = false;
        s.num = abs(num);
        solutions.push_back(s);
    }
    sort(solutions.begin(),solutions.end(),compare);
    for(int i=1;i<solutions.size();i++)
    {
        if(solutions[i].acid != solutions[i-1].acid && abs(solutions[i].num-solutions[i-1].num) < minimumGap)
        {
            minimumGap = abs(solutions[i].num-solutions[i-1].num);
            answer = i;
        }
        if(check && solutions[i].acid == solutions[i-1].acid)
        {
            check = false;
            if(abs(solutions[i].num+solutions[i-1].num) < minimumGap)
            {
                minimumGap = abs(solutions[i].num+solutions[i-1].num);
                answer = i;
            }
        }
    }
    int solution_1, solution_2;
    if(solutions[answer-1].acid==true)  solution_1 = -solutions[answer-1].num;
    else    solution_1 = solutions[answer-1].num;
    if(solutions[answer].acid==true)  solution_2 = -solutions[answer].num;
    else    solution_2 = solutions[answer].num;
    
    if(solution_1<solution_2)   cout<<solution_1<<" "<<solution_2;
    else    cout<<solution_2<<" "<<solution_1;
    return 0;
}

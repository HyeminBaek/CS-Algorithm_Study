#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

pair<int,int> getPos(int n)
{
    if(n==0) return make_pair(3,1);
    int row = (n-1)/3;
    int col = (n-1)%3;
    return make_pair(row,col);
}

int getLength(pair<int,int> pos, pair<int,int> target)
{
    return abs(pos.first-target.first)+abs(pos.second-target.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left = make_pair(3,0);
    pair<int,int> right = make_pair(3,2);
    pair<int,int> target;
    
    for(int i=0;i<numbers.size();i++)
    {
        target = getPos(numbers[i]); 
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7)
        {
            left = target;
            answer += "L";
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9)
        {
            right = target;
            answer += "R";
        }
        else
        {
            if(getLength(left,target)<getLength(right,target))
            {
                left = target;
                answer += "L";
            }
            else if(getLength(left,target)>getLength(right,target))
            {
                right = target;
                answer += "R";
            }
            else
            {
                if(hand=="left")
                {
                    left = target;
                    answer += "L";
                }
                else
                {
                    right = target;
                    answer += "R";
                }
            }
        }
    }
    
    return answer;
}

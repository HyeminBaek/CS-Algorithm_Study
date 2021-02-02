#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define pci pair<char,int>
vector<char> priority;

long long solution(string expression) {
    long long answer = 0;
    vector<pci> opr_idx;
    vector<string> num_vec;

    string num="";
    for(int i=0; i<expression.length(); i++)
    {
        char c = expression[i];
        if(!isdigit(c)) {
            num_vec.push_back(num);
            num_vec.push_back(to_string(c));
            opr_idx.push_back({c,num_vec.size()-1});
            if( find(priority.begin(),priority.end(),c)==priority.end() ) priority.push_back(c);
            num="";
        }
        else{
            num+=c;
        }
    }
    num_vec.push_back(num);
    sort(priority.begin(),priority.end());
    do{
         sort(opr_idx.begin(), opr_idx.end(), 
         [] (pci &l, pci &r){
            if( find(priority.begin(), priority.end(), l.first) ==  find(priority.begin(), priority.end(), r.first))
                return l.second < r.second;
            else return find(priority.begin(), priority.end(), l.first) <  find(priority.begin(), priority.end(), r.first);     
         }); 
        
        long long tmp_tot = -1;
        vector<string> num_tmp = num_vec;
        
        for(pci tmp : opr_idx){
            for(int i=1; i<num_tmp.size(); i++){
                if(num_tmp[i] == to_string(tmp.first)){                 
                    long long left = stoll(num_tmp[i-1]);
                    long long right = stoll(num_tmp[i+1]);
                                        
                    if(tmp.first == '*') tmp_tot = left*right;
                    else if(tmp.first == '+') tmp_tot=left+right;
                    else if(tmp.first == '-') tmp_tot =left-right;
                    
                    num_tmp[i]=to_string(tmp_tot);
                    num_tmp.erase(num_tmp.begin()+i-1);
                    num_tmp.erase(num_tmp.begin()+i);
                    i--;
                }
            }
        }
        answer = max(answer,abs(tmp_tot));
    }while(next_permutation(priority.begin(),priority.end()));
    
    return answer;
}

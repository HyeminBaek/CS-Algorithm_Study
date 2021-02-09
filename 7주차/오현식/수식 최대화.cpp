#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> priority = {'*','+','-'};// *,+,-
unordered_map<char,int> p;

struct Operator
{
    char op;
    int prev;
    Operator(char c='o',int p=0):op(c),prev(p){}
};

bool compare(Operator op1, Operator op2)
{
    if(op1.op==op2.op)  return op1.prev<op2.prev;
    else    return p[op1.op]>p[op2.op];
}

long long find(vector<long long> expression_operands, vector<Operator> expression_operators)
{
    int prev, next;
    long long update;
    for(int i=0;i<expression_operators.size();i++)
    {
        prev = expression_operators[i].prev;
        next = expression_operators[i].prev+1;
        switch(expression_operators[i].op)
        {
            case '+':
                update = expression_operands[prev]+expression_operands[next];
                expression_operands[prev] = update;
                break;
            case '-':
                update = expression_operands[prev]-expression_operands[next];
                expression_operands[prev] = update;
                break;
            case '*':
                update = expression_operands[prev]*expression_operands[next];
                expression_operands[prev] = update;
                break;
        }
        expression_operands.erase(expression_operands.begin()+next);
        for(int i=0;i<expression_operators.size();i++)  if(expression_operators[i].prev>=next)  expression_operators[i].prev -= 1;
    }
    return abs(update); 
}

long long solution(string expression) {
    long long answer = 0;
    size_t idx=0;
    long long operand;
    Operator *op;
    vector<long long> expression_operands;
    vector<Operator> expression_operators;
    while(!expression.empty())
    { 
        if(isdigit(expression[0]))    
        {
            operand = stoll(expression,&idx);
            expression_operands.push_back(operand);
            expression = expression.substr(idx);
        }
        else    
        {
            op = new Operator(expression[0],expression_operands.size()-1);
            expression_operators.push_back(*op);
            expression = expression.substr(1);
        }
    } 
    do{
        for(int i=0;i<priority.size();i++)  p[priority[i]] = 3-i;
        sort(expression_operators.begin(),expression_operators.end(),compare); 
        answer = max(answer,find(expression_operands,expression_operators));
    }while(next_permutation(priority.begin(),priority.end()));
    return answer;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<string,vector<string>> parents;
unordered_map<string,double> similarity;

double getSimilarity(string candidate)
{
    if(similarity[candidate]!=0)    return similarity[candidate];
    if(parents[candidate].size()==0)    return 0;
    
    similarity[candidate] = (getSimilarity(parents[candidate][0]) + getSimilarity(parents[candidate][1]))/2;
    return similarity[candidate];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string founder;
    string child, parent1, parent2;
    string successor = "nil", candidate;
    cin>>N>>M;
    cin>>founder;
    for(int i=0;i<N;i++)
    {
        cin>>child>>parent1>>parent2;
        parents[child].push_back(parent1);
        parents[child].push_back(parent2);
    }
    similarity[founder]=1;
    for(int i=0;i<M;i++)
    {
        cin>>candidate;
        successor = similarity[successor] < getSimilarity(candidate) ? candidate : successor;
    }
    cout<<successor;
    return 0;
}

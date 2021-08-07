#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int N, M;
vector<unsigned int> words;
unsigned int memory = UINT_MAX;

int main(int argc, const char * argv[]) {
    string word;
    int cmd;
    char alphabet;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>word;
        unsigned int bitOfWord=0;
        for(int j=0;j<word.size();j++)  bitOfWord |= (1<<(word[j]-'a'));
        words.push_back(bitOfWord);
    }
    for(int i=1;i<=M;i++){
        int ans=0;
        cin>>cmd>>alphabet;
        switch(cmd){
            case 1:
                memory &= ~(1<<(alphabet-'a'));
                break;
            case 2:
                memory |= (1<<(alphabet-'a'));
                break;
        }
        for(int i=0;i<words.size();i++) if((words[i]&memory) == words[i])   ans++;
        cout<<ans<<endl;
    }
    return 0;
}

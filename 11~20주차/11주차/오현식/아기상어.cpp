#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
typedef pair<int,int>   Pos;
typedef pair<Pos,int>   State;

int N;
int fishbowl[21][21];   // babyShark 제외한 fish들 표시
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct compare{
    bool operator()(State s1, State s2){
        if(s1.second==s2.second){
            if(s1.first.first==s2.first.first)  return s1.first.second>s2.first.second;
            else    return s1.first.first>s2.first.first;
        }
        else return s1.second>s2.second;
    }
};

struct BabyShark{
    Pos pos;
    int sizeOfBabyShark;
    int lifetime;
    int numOfFishBabySharkAte;
    
    BabyShark():sizeOfBabyShark(2),lifetime(0),numOfFishBabySharkAte(0){}
    bool move(void){
        bool visited[21][21] = {false,};
        priority_queue<State,vector<State>,compare> que;
        visited[pos.first][pos.second]=true;
        que.push(State(pos,0));
        while(!que.empty())
        {
            Pos currentPos = que.top().first;
            int currentDist = que.top().second;
            que.pop();
            if(isEdible(currentPos)){
                fishbowl[currentPos.first][currentPos.second] = 0;
                lifetime += currentDist;
                numOfFishBabySharkAte++;
                if(numOfFishBabySharkAte==sizeOfBabyShark){
                    sizeOfBabyShark++;
                    numOfFishBabySharkAte=0;
                }
                pos = currentPos;
                return true;
            }
            
            loop(i,0,4){
                Pos nextPos = Pos(currentPos.first+dx[i],currentPos.second+dy[i]);
                if(isOutOfBound(nextPos) || visited[nextPos.first][nextPos.second] || fishbowl[nextPos.first][nextPos.second]>sizeOfBabyShark)   continue;
                visited[nextPos.first][nextPos.second]=true;
                que.push(State({nextPos,currentDist+1}));
            }
        }
        
        return false;
    }
    bool isEdible(Pos pos){
        if(fishbowl[pos.first][pos.second]>0 && fishbowl[pos.first][pos.second] < sizeOfBabyShark)   return true;
        return false;
    }
    bool isOutOfBound(Pos pos){
        if(pos.first<1 || pos.first>N || pos.second<1 || pos.second>N)  return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    BabyShark babyShark;
    cin>>N;
    loop(i,1,N+1){
        loop(j,1,N+1){
            cin>>fishbowl[i][j];
            if(fishbowl[i][j]==9){
                babyShark.pos = Pos(i,j);
                fishbowl[i][j]=0;
            }
        }
    }
    while(babyShark.move()){}
    cout<<babyShark.lifetime;
    return 0;
}

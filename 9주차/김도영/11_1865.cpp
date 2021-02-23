#include <iostream>
#include <vector>

const int MAX = 501;
const int INF = 1e9;
using namespace std;

int n, m, w;
vector<pair<pair<int, int>, int>> graph;
int Dist[MAX];
bool Cycle = false;

void Bellman_Fore(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<graph.size(); j++){
            int start = graph[j].first.first;
            int end = graph[j].first.second;
            int cost = graph[j].second;

            if(Dist[start] == INF) continue;
            if(Dist[start]+cost < Dist[end]){
                Dist[end] = Dist[start]+cost;
                if(i == n){
                    Cycle = true;
                }
            }
        }
    }
}

int main(){
    int TC; cin >> TC;
    while(TC--){
        Cycle = false;
        graph.clear();
        fill(Dist, Dist+MAX, INF);

        cin >> n >> m >> w;
        for(int i=0; i<m; i++){
            int s,e,t; cin >> s >> e >> t;
            graph.push_back({{s,e}, t});
            graph.push_back({{e,s}, t});
        }

        for(int i=0; i<w; i++){
            int s,e,t; cin >> s >> e >> t;
            graph.push_back({{s,e}, (t*-1)});
        }

        Dist[1] = 0;
        Bellman_Fore();
        if(Cycle){
            cout << "YES" << "\n";
        }   
        else{
            cout << "NO" << "\n";
        }
    }
}
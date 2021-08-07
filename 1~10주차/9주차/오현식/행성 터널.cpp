#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Planet {
    int noOfPlanet;
    int x, y, z;
    Planet(int No=0,int X=0,int Y=0,int Z=0):noOfPlanet(No),x(X),y(Y),z(Z){}
};

struct Edge {
    int u, v;
    int cost;
    Edge(int U,int V,int C):u(U),v(V),cost(C){}
};

struct Vertex {
    int parent;
    int rank;
};

int N;
int x, y, z;
vector<Planet> planets;
vector<Edge> edges;
Vertex vertex[100001];

bool compareByX(Planet &p1, Planet &p2){
    return p1.x<p2.x;
}

bool compareByY(Planet &p1, Planet &p2){
    return p1.y<p2.y;
}

bool compareByZ(Planet &p1, Planet &p2){
    return p1.z<p2.z;
}

bool compare(Edge &e1, Edge &e2){
    return e1.cost<e2.cost;
}

int find(int v) {
    if(vertex[v].parent == v)   return v;
    else return vertex[v].parent = find(vertex[v].parent);
}

bool merge(int v1, int v2) {
    int r1 = find(v1);
    int r2 = find(v2);
    if(r1==r2)  return false;
    
    if(vertex[r1].parent<vertex[r2].rank)   vertex[r1].parent = r2;
    else if(vertex[r1].parent>vertex[r2].rank) vertex[r2].parent = r1;
    else if(vertex[r1].parent==vertex[r2].rank) {
        vertex[r1].parent = r2;
        vertex[r2].rank++;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer=0;
    int cnt=0;
    Planet u, v;
    cin>>N;
    for(int i=1;i<=N;i++){
        vertex[i].parent = i;
        vertex[i].rank = 0;
    }
    for(int i=1;i<=N;i++){
        cin>>x>>y>>z;
        planets.push_back(Planet(i,x,y,z));
    }
    sort(planets.begin(),planets.end(),compareByX);
    for(int i=0;i<planets.size()-1;i++) {
        int cost = abs(planets[i].x-planets[i+1].x);
        edges.push_back(Edge(planets[i].noOfPlanet,planets[i+1].noOfPlanet,cost));
    }
    sort(planets.begin(),planets.end(),compareByY);
    for(int i=0;i<planets.size()-1;i++) {
        int cost = abs(planets[i].y-planets[i+1].y);
        edges.push_back(Edge(planets[i].noOfPlanet,planets[i+1].noOfPlanet,cost));
    }
    sort(planets.begin(),planets.end(),compareByZ);
    for(int i=0;i<planets.size()-1;i++) {
        int cost = abs(planets[i].z-planets[i+1].z);
        edges.push_back(Edge(planets[i].noOfPlanet,planets[i+1].noOfPlanet,cost));
    }
    sort(edges.begin(),edges.end(),compare);
    for(int i=0 ; i<edges.size() && cnt<N-1 ; i++){
        if(merge(edges[i].u, edges[i].v))  {
            answer+=edges[i].cost;
            cnt++;
        }
    }
    cout<<answer;
    return 0;
}

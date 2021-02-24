#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char image[512][512];
int n;
int row, col;

string decToBin(int dec){
    string bin;
    for(int i=0;i<4;i++){
        bin = to_string(dec%2) + bin;
        dec/=2;
    }
    return bin;
}

string hexToBin(char hex){
    string bin;
    int dec;
    if(isalpha(hex))    dec = hex - 'a' + 10;
    else dec = hex - '0';
    return decToBin(dec);
}

void setImage(string bin){
    for(int idx=0;idx<bin.size();idx++){
        image[row][col++] = bin[idx];
    }
    if(col>=n){
        row++;
        col=0;
    }
}

bool isSame(int x, int y, int N){
    char first = image[x][y];
    for(int i=x;i<x+N;i++){
        for(int j=y;j<y+N;j++)  if(image[i][j]!=first) return false;
    }
    return true;
}

char getColor(char c){
    if(c=='0')  return 'W';
    else return 'B';
}

void printQuadTree(int x, int y, int N){
    if(N==1)
    {
        cout<<getColor(image[x][y]);
        return;
    }
    if(!isSame(x,y,N)){
        cout<<"Q";
        for(int i=x;i<x+N;i+=N/2){
            for(int j=y;j<y+N;j+=N/2) printQuadTree(i,j,N/2);
        }
    }
    else    cout<<getColor(image[x][y]);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string line;
    getline(cin,line);
    getline(cin,line);
    n = stoi(line.substr(23));
    getline(cin,line);
    for(int i=0;i<n;i++){
        getline(cin,line);
        string bin;
        char *cstr = new char[line.length()+1];
        strcpy(cstr, line.c_str());
        char *p = strtok(cstr,",");
        while(p!=NULL){
            //
            for(int j=0;j<2;j++) bin += hexToBin(p[j+2]);
            reverse(bin.begin(), bin.end());
            setImage(bin);
            bin.clear();
            //
            p = strtok(NULL,",");
        }
        delete[] cstr;
    }
    getline(cin,line);
    cout<<n<<endl;
    printQuadTree(0,0,n);
    return 0;
}

#include<iostream>
#include <vector>
#include <string>
using namespace std;
  
int K, answer;
vector<int> v;
bool visited[20];
  
void back(int idx,int cnt, int target, int sum)
{
    if(sum>K) return;
    if (cnt == target)
    {
        if (sum == K)
        {
            answer++; return;
        }
    }
    else
    {
        for (int k = idx; k < v.size(); k++)
        {
            if (!visited[k])
            {
                visited[k] = true;
                back(k,cnt + 1, target, sum + v[k]);
                visited[k] = false;
            }
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T; cin >> T;
  
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N; cin >> N >> K;
        answer = 0; v.clear();
  
        for (int i = 0; i < N; i++)
        {
            int x; cin >> x; v.push_back(x);
            visited[i]=false;
        }
        for (int i = 1; i <= v.size(); i++)
        {
            back(0,0, i, 0);
        }
  
        cout << '#' << test_case << " " << answer << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

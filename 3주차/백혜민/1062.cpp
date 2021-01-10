#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer, N, K;
bool abc[26]; //배운 글자를 저장하기 위한 배열
vector<string> sub;

void recur(int idx, int size)
{
	if (size == K-5)//단어를 다 배움
	{
		int n = 0;
		for (int i = 0; i < sub.size(); i++) //입력받은 단어들을 읽을 수 있나 비교
		{
			bool flag = false;
			for (int j = 0; j < sub[i].length(); j++)
			{
				if (!abc[sub[i][j]-'a']) //현재 배운 단어에 포함되지 않은 알파벳이 있는 경우
				{
					flag = true; break;
				}
			}
			if (!flag)
				n++;
		}
		answer = (answer < n) ? n : answer;
	}
	else
	{
		for (int i = idx; i < 26; i++)
		{
			if (!abc[i]) //백트래킹을 하면서 알파벳 전부 방문해봄
			{
				abc[i] = true;
				recur(i, size + 1);
				abc[i] = false;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    //남극 언어의 단어를 읽으려면 a,c,i,t,n 필요
	abc[0] = 1, abc[2] = 1, abc['i' - 'a'] = 1, abc['n' - 'a'] = 1, abc['t' - 'a'] = 1;

	cin >> N >> K;
	if (K < 5) //단어를 읽으려면 a,c,i,t,n 전부 필요하기 때문에 못읽음
	{
		cout << 0; return 0;
	}
	else if (K == 26) //알파벳을 전부 포함하여 모든 단어를 다 읽을 수 있음
	{
		cout << N; return 0;
	}
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		string temp = "";
		for (int j = 4; j <= s.length() - 5; j++)
			temp += s[j];

		sub.push_back(temp);
	}

	recur(0, 0);
	cout << answer;

	return 0;
}

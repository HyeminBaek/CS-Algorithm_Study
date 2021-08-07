#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
sol) 슬랙에 정리한 걸 그대로 적용하였다
apple 이면 2^'a'-'a' + 2^'p'-'a' ...
*/

vector<int> original; //아예 모든 걸 비트마스크로 표기해야 시간초과 안남

int count(const int); //완전히 알고 있는 단어를 세는 함수
void init(int&, int&); //초기화 함수

int main()
{
	int M;
	int whole = 0;

	init(M, whole);

	for (int i = 0; i < M; i++)
	{
		int o; char x; cin >> o >> x;

		int ascii = x - 'a';

		switch(o) {
		case 1:
			whole = whole & ~(1 << ascii);
			break;
		case 2:
			whole = whole | (1 << ascii);
		}
		cout << count(whole) << "\n";
	}

	return 0;
}
int count(const int whole)
{
	int answer = 0;

	for (int i = 0; i < original.size(); i++)
	{
		/* 처음 시간초과 난 코드
		bool flag = true;

		for (int j = 0; j < original[i].length(); j++)
		{
			int ascii = original[i][j] - 'a';

			if ((whole & (1 << ascii)) == 0)
			{
				flag = false; break;
			}
		}
		if (flag) answer++;
		*/

		if ((whole&original[i]) == original[i]) answer++;
	}

	return answer;
}
void init(int& M,int& whole)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N >> M;

	bool check[26] = { false, }; //전체 알파벳을 비트마스크 형식으로 저장하기 위한 임시 배열
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;

		int remove = 0; 

		//연산 시간을 줄이고자 입력 값에서 중복되는 알파벳을 제거하였다
		bool arr[26] = { false, };
		for (int j = 0; j < s.length(); j++)
		{
			arr[s[j] - 'a'] = true; check[s[j] - 'a'] = true;
		}
		for (int j = 0; j < 26; j++)
			if (arr[j])  remove += (1 << j);
		
		original.push_back(remove);
	}
	for (int j = 0; j < 26; j++)
		if (check[j]) 	whole += (1 << j);
}

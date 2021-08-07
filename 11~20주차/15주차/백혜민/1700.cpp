#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int arr[101], m[101];
vector<int> q; //멀티탭 역할

int sol()
{
	int answer = 0;

	for (int i = 0; i < K; i++)
	{
		bool plug = false;

		if (find(q.begin(), q.end(), arr[i]) != q.end()) plug = true;
		
		if (q.size() < N) //아직 멀티탭에 더 꽂을 수 있는 경우
		{
			if (!plug) //멀티탭에 안 꽂혀있는 경우 꽂아주고 횟수 감소
			{
				q.push_back(arr[i]);	m[arr[i]]--;
			}
			else
			{
				for (int j = 0; j < q.size(); j++) 
				{
					if (q[j] == arr[i])
					{
						m[q[j]]--; break;
					}
				}
			}
		}
		else //멀티탭이 꽉 찼을 때
		{
			if (!plug) //플러그가 멀티탭에 안 꽂혀있을 때
			{
				bool flag = false;
				for (int j = 0; j < q.size(); j++) //앞으로 안나오는 플러그가 꽂혀있을 때
				{
					if (m[q[j]] == 0)
					{
						answer++;//플러그를 뽑음
						--m[arr[i]];
						q[j] = arr[i];
						flag = true; break; //값이 변동되었음을 의미
					}
				}
				if (!flag) //앞으로 안나오는 플러그가 없을 때
				{
					//다음 차례가 제일 늦는 플러그를 뽑는다
					int idx = -1, val = -1;
					for (int l = 0; l < q.size(); l++)//다음 차례가 늦는 플러그 찾기
					{
						for (int j = i + 1; j < K; j++)
						{
							if (arr[j] == q[l])
							{
								if (j > idx)
								{
									idx = j; val = l;
								}
								break;
							}
						}
					}
					--m[arr[i]];
					q[val] = arr[i];
					answer++;
				}
			}
			else
			{
				for (int j = 0; j < q.size(); j++)
				{
					if (q[j] == arr[i])
					{
						m[q[j]]--; break;
					}
				}
			}
		}
	}

	return answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		m[arr[i]]++; //총 사용 횟수 체크
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}

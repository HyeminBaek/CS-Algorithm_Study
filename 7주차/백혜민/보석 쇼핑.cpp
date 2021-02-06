vector<int> solution(vector<string> gems) {
	/*
	1. 맵과 셋을 이용하였다. 여기서 셋은 간편하게 중복을 제거하기 위함
	2. 풀었던 두 용액과 같은 방법으로 투포인터를 이용하여 문제를 풀었다.
	*/
	vector<int> answer;
	answer.push_back(123456789); answer.push_back(987654321); //임의의 최댓값으로 초기화

	set<string> distinctG;//매개변수로 들어온 벡터 중복을 없앤 것
	map<string, int> countG;
	for (int i = 0; i < gems.size(); i++)
		distinctG.insert(gems[i]);

	int low = 0;

	for (int i = 0; i < gems.size(); i++)
	{

		if (countG.find(gems[i]) == countG.end()) countG.insert({ gems[i],1 });
		else countG[gems[i]]++;

		if (countG.size() == distinctG.size())
		{
			while (low < gems.size())
			{
				if (countG[gems[low]] > 1)
					--countG[gems[low++]];
				else
					break;
			}
			if (answer[1] - answer[0] > (i + 1) - (low + 1)) //가장 짧은 구간을 찾아줘야하기 때문
			{
				answer[0] = low + 1; answer[1] = i + 1;
			}
		}
	}

	return answer;
}

struct person
{
	string language, career, exprience, soulfood;
	int score;
};
person split(int i,vector<string> info)
{
	string temp = ""; int idx = 0;
	person p = { "","","","",0 };
	for (int j = 0; j < info[i].size(); j++)
	{
		if (info[i][j] == ' ')
		{
			if (temp != "and")
			{
				if (idx == 0)
				{
					p.language = temp; idx++;
				}
				else if (idx == 1)
				{
					p.career = temp; idx++;
				}
				else if (idx == 2)
				{
					p.exprience = temp; idx++;
				}
				else if (idx == 3)
				{
					p.soulfood = temp; idx++;
				}
			}
			temp = "";
		}
		else
			temp += info[i][j];
	}

	if (temp == "-") p.score = -1;
	else p.score = stoi(temp);

	return p;
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	vector<person> infoSplit,querySplit;
	for (int i = 0; i < info.size(); i++)
	{
		person p = split(i, info);
		infoSplit.push_back(p);
	}
	for (int i = 0; i < query.size(); i++)
	{
		person p = split(i, query);
		querySplit.push_back(p);
	}

	for (int i = 0; i < querySplit.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < infoSplit.size(); j++)
		{
			if (infoSplit[j].language == querySplit[i].language || querySplit[i].language=="-")
			{
				if (infoSplit[j].career == querySplit[i].career || querySplit[i].career == "-")
				{
					if (infoSplit[j].exprience == querySplit[i].exprience || querySplit[i].exprience == "-")
					{
						if (infoSplit[j].soulfood == querySplit[i].soulfood || querySplit[i].soulfood == "-")
						{
							if (infoSplit[j].score >= querySplit[i].score || querySplit[i].score == -1)
							{
								cnt++;
							}
						}
					}
				}
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}

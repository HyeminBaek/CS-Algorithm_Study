string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left = 10, right = 10;

	int arr[11][9]; 
	arr[1][2] = 1, arr[1][5] = 2, arr[1][8] = 3, arr[1][0] = 4;
	arr[4][2] = 2, arr[4][5] = 1, arr[4][8] = 2, arr[4][0] = 3;
	arr[7][2] = 3, arr[7][5] = 2, arr[7][8] = 1, arr[7][0] = 2;

	arr[3][2] = 1, arr[3][5] = 2, arr[3][8] = 3, arr[3][0] = 4;
	arr[6][2] = 2, arr[6][5] = 1, arr[6][8] = 2, arr[6][0] = 3;
	arr[9][2] = 3, arr[9][5] = 2, arr[9][8] = 1, arr[9][0] = 2;

	arr[2][2] = 0, arr[2][5] = 1, arr[2][8] = 2, arr[2][0] = 3;
	arr[5][2] = 1, arr[5][5] = 0, arr[5][8] = 1, arr[5][0] = 2;
	arr[8][2] = 2, arr[8][5] = 1, arr[8][8] = 0, arr[8][0] = 1;
	arr[0][2] = 3, arr[0][5] = 2, arr[0][8] = 1, arr[0][0] = 0;

	arr[10][2] = 4, arr[10][5] = 3, arr[10][8] = 2, arr[10][0] = 1;

	bool l = false, r = false;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0)
		{
			if (arr[left][numbers[i]] < arr[right][numbers[i]]) l = true;
			else if (arr[left][numbers[i]] > arr[right][numbers[i]]) r = true;
			else
			{
				if (hand == "right") r = true;
				else l = true;
			}
		}
		else
		{
			if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) l = true;
			else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) r = true;
		}

		if (l)
		{
			left = numbers[i];
			answer += "L";
		}
		else if (r)
		{
			right = numbers[i];
			answer += "R";
		}

		l = false, r = false;
	}
    
    return answer;
}

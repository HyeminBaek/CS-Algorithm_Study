#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
bool compare(pii p1, pii p2) {
	if (p1.second < p2.second) {
		return true;
	}
	else if (p1.second > p2.second) {
		return false;
	}
	else {
		return p1.first < p2.first;
	}
}
int r, c, k,A[100][100],rn,cn;
void opRow() {
	int msz = 0;
	vector<int> temp;
	vector<pii> temp2[100];
	
	for (int i = 0; i < rn; i++) {
		temp.clear();
		
		for (int j = 0; j < cn; j++) {
			
			if (A[i][j] != 0) {
				temp.push_back(A[i][j]);
				
			}
			
		}
		sort(temp.begin(), temp.end());
		
		pii t(0, 0);
		for (int j = 0; j < temp.size(); j++) {
			if (t.first != temp[j]) {
				if (t.first != 0) {
					temp2[i].push_back(t);
				}
				t.first = temp[j];
				t.second = 1;
			}
			else {
				t.second++;
			}
		}
		temp2[i].push_back(t);
		sort(temp2[i].begin(), temp2[i].end(),compare);
		
	}
	for (int i = 0; i < rn; i++) {
		msz = msz < temp2[i].size() ? temp2[i].size() : msz;
	}
	msz = msz > 50 ? 50 : msz;
	for (int i = 0; i < rn; i++) {
		for (int j = 0; j <msz; j++) {
			if (j < temp2[i].size()) {
				A[i][j * 2] = temp2[i][j].first;
				A[i][j * 2 + 1] = temp2[i][j].second;
			}
			else {
				A[i][j * 2] = 0;
				A[i][j * 2 + 1] = 0;
			}
		}
		
	}
	cn = msz * 2;
}
void opCol() {
	int msz = 0;
	vector<int> temp;
	vector<pii> temp2[100];

	for (int i = 0; i < cn; i++) {
		temp.clear();

		for (int j = 0; j < rn; j++) {

			if (A[j][i] != 0) {
				temp.push_back(A[j][i]);

			}

		}
		sort(temp.begin(), temp.end());

		pii t(0, 0);
		for (int j = 0; j < temp.size(); j++) {
			if (t.first != temp[j]) {
				if (t.first != 0) {
					temp2[i].push_back(t);
				}
				t.first = temp[j];
				t.second = 1;
			}
			else {
				t.second++;
			}
		}
		temp2[i].push_back(t);
		sort(temp2[i].begin(), temp2[i].end(), compare);

	}
	for (int i = 0; i < cn; i++) {
		msz = msz < temp2[i].size() ? temp2[i].size() : msz;
	}
	msz = msz > 50 ? 50 : msz;
	for (int i = 0; i < cn; i++) {
		for (int j = 0; j < msz; j++) {
			if (j < temp2[i].size()) {
				A[j*2][i] = temp2[i][j].first;
				A[j*2+1][i] = temp2[i][j].second;
			}
			else {
				A[j*2][i] = 0;
				A[j*2+1][i] = 0;
			}
		}

	}
	rn = msz * 2;
}
int main() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			A[i][j] = 0;
		}
	}
	scanf("%d%d%d", &r, &c, &k);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &A[i / 3][i % 3]);
	}
	rn = 3, cn = 3;
	int answer = -1;
	for (int i = 0; i <= 100; i++) {
		if (A[r - 1][c - 1] == k) {
			answer = i;
			break;
		}
		int msz = 0;
		if (rn >= cn) {
			opRow();
		}
		else {
			opCol();
		}
	
	}
	printf("%d\n", answer);

	return 0;
}
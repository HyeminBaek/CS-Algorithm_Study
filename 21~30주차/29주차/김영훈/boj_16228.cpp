#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
int Parsing(string s);
int Result(vector<int>& v);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	cout << Parsing(s) << "\n";
	return 0;
}
int Parsing(string s) {
	int idx = 0;
	int val=0;
	vector<int> op;
	op.clear();
	while (idx < s.size()) {
		switch (s[idx]) {
		case '+':
			op.push_back(val);
			op.push_back(0);
			val = 0;
			break;
		case '-':
			op.push_back(val);
			op.push_back(1);
			val = 0;
			break;
		case '<':
			op.push_back(val);
			op.push_back(2);
			val = 0;
			idx++;
			break;
		case '>':
			op.push_back(val);
			op.push_back(3);
			val = 0;
			idx++;
			break;
		default:
			if (s[idx] == '(') {
				int ct = 0;
				string sstr = "";
				idx++;
				while (1) {
					if (ct == 0 && s[idx] == ')') {
						val = Parsing(sstr);
						break;
					}
					sstr += s[idx];
					if (s[idx] == '(') {
						ct++;
					}
					else if (s[idx] == ')') {
						ct--;
					}
					idx++;
				}
			}
			else {
				val *= 10;
				val += (s[idx] - '0');
			}
			break;
		}
		idx++;
	}
	op.push_back(val);
	return Result(op);
}
int Result(vector<int>& v) {
	
	vector<int> temp;
	temp.clear();
	temp.push_back(v[0]);
	for (int i = 1; i < v.size(); i+=2) {
		switch (v[i]) {
		case 2:
			temp.back() = min(temp.back(), v[i + 1]);
			break;
		case 3:
			temp.back() = max(temp.back(), v[i + 1]);
			break;
		default:
			temp.push_back(v[i]);
			temp.push_back(v[i + 1]);
			break;
		}
	}
	int ret = temp[0];
	for (int i = 1; i < temp.size(); i += 2) {
		switch (temp[i]) {
		case 0:
			ret += temp[i + 1];
			break;
		case 1:
			ret -= temp[i + 1];
			break;
		}
	}

	return ret;
}
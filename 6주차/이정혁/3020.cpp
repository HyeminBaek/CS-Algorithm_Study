#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int bottom[500001] = { 0, };
int top[500001] = { 0, };
int mini[200001] = { 0, };
int main(void) {
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		int len1, len2;
		cin >> len1 >> len2;
		bottom[len1]++;
		top[len2]++;
	}
	int minimum = n;
	int value_bottom, value_top, value1=0,value2=0;
	for (int i = 0; i < h; i++) {
		value1 += bottom[i];
		value_bottom = n / 2 - value1;
		value2 += top[h - i];
		value_top = value2;
		minimum = min(minimum, value_bottom + value_top);
		mini[value_bottom + value_top]++;
	}
	cout << minimum << " "<<mini[minimum]<< endl;
}

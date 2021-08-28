#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200000],d[400000],d2[200000],f[200000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n-1; i++) {
		d[i] = a[i + 1] - a[i];
		d[i+n] = d[i];
	}
	d[n - 1] = 360000+a[0]-a[n-1];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n-1; i++) {
		d2[i] = a[i + 1] - a[i];
	}

	int j = 0;
	f[0] = 0;
	for (int i = 1; i < n - 1; i++) {
		f[i] = 0;
		while (j > 0 && d2[i] != d2[j]) {
			j = f[j-1];
		}
		if (d2[i] == d2[j]) {
			f[i] = ++j;
		}

	}

	j = 0;
	bool ans = false;
	for (int i = 0; i < n * 2 - 1; i++) {
		while (j > 0 && d[i]!=d2[j]) {
			j = f[j - 1];
		}
		if (d[i] == d2[j]) {
			j++;
			if (j == n-1) {
				ans = true;
				break;
			}
		}

	}
	printf("%s\n", (ans ? "possible" : "impossible"));
	return 0;
}
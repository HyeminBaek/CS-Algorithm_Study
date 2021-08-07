#include <iostream>
#include <algorithm>
using namespace std;

void sol()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int Min[3], Max[3], temp[3];

	int z, o, t; cin >> z >> o >> t;
	Min[0] = z, Min[1] = o, Min[2] = t, Max[0] = z, Max[1] = o, Max[2] = t;

	for (N; N > 1; N--)
	{
		cin >> z >> o >> t;

		temp[0] = z, temp[1] = o, temp[2] = t;

		z += min(Min[0], Min[1]);
		o += min(Min[0], min(Min[1], Min[2]));
		t += min(Min[1], Min[2]);

		Min[0] = z, Min[1] = o, Min[2] = t;

		z = temp[0], o = temp[1], t = temp[2];

		z += max(Max[0], Max[1]);
		o += max(Max[0], max(Max[1], Max[2]));
		t += max(Max[1], Max[2]);

		Max[0] = z, Max[1] = o, Max[2] = t;
	}

	cout << max(Max[0], max(Max[1], Max[2])) << " " << min(Min[0], min(Min[1], Min[2]));
}
int main()
{
	sol();

	return 0;
}

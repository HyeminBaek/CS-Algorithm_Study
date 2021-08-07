#include<iostream>
using namespace std;
const int INF = (((1 << 30)-1)<<1);
class SGT {
public:
	int* tree;
	int* leaf;
	int N;
	SGT(int N) {
		this->N = N;
		int sz = 2;
		while (sz < N) {
			sz *= 2;
		}
		tree = new int[2*sz];
		leaf = new int[N+1];
		for (int i = 1; i < 2 * sz; i++) {
			tree[i] = INF;
		}
		
	}
	~SGT() {
		delete[] tree;
		delete[] leaf;
	}
	void Insert(int index, int data) {
		int s = 1, e = N, pos = 1;
		while (1) {
			tree[pos] = tree[pos] > data ? data : tree[pos];
			if (s == e) {
				leaf[index] = pos;
				break;
			}
			int m = (s + e) / 2;
			if (m >= index) {
				e = m;

			}
			else {
				s = m + 1;
			}
			pos = pos * 2 + (m < index);
		}
	}
	void Update(int index, int data) {
		int npos = leaf[index];
		tree[npos] = data;
		npos /= 2;
		while (npos > 0) {
			tree[npos] = tree[npos * 2] > tree[npos * 2 + 1] ? tree[npos * 2 + 1] : tree[npos * 2];
			npos /= 2;
		}
	}
	int Search(int s, int e, int pos, int fs, int fe) {
		if (fs==s && fe==e) {
			return tree[pos];
		}
		int ret = INF;
		int m = (s + e) / 2;
		if (m >= fs) {
			int r = Search(s, m, pos * 2, fs, fe < m ? fe : m);
			ret = ret > r ? r : ret;
		}
		if (m < fe) {
			int r = Search(m + 1, e, pos * 2 + 1, m + 1 < fs ? fs : m + 1, fe);
			ret = ret > r ? r : ret;
		}

		return ret;

	}
};
int N, M,a,b,c;
int main() {
	scanf("%d", &N);
	SGT sgt(N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		sgt.Insert(i, a);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			sgt.Update(b, c);
		}
		else {
			printf("%d\n", sgt.Search(1, N, 1, b, c));
		}
	}
	return 0;
}
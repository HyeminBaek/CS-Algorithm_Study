#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
int N, K;
string name;
struct Node {
	string name;
	vector<Node> childs;
	unordered_map<string, int> childs_map;
	Node() {
		name = "";
		childs.clear();
		childs_map.clear();
	}
	Node(string name) {
		this->name = name;
		childs.clear();
		childs_map.clear();
	}
};
Node root = Node();
bool compNode(const Node& a, const Node& b) {
	return a.name < b.name;
}
void DFS(Node* now, string prefix) {
	sort(now->childs.begin(), now->childs.end(), compNode);
	if (!now->name.empty()) {
		cout << prefix << now->name << "\n";
	}
	for (int i = 0; i < now->childs.size(); i++) {
		DFS(&now->childs[i], now->name.empty() ? "" : prefix + "--");
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		Node* now = &root;
		for (int j = 0; j < K; j++) {
			cin >> name;
			if (now->childs_map.count(name) == 0) {
				now->childs_map[name] = now->childs.size();
				now->childs.push_back(Node(name));
			}
			now = &now->childs[now->childs_map[name]];
		}
	}
	DFS(&root, "");
	return 0;
}
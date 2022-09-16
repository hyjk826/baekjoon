#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int> > vec[100001];
int ch[100001]{};
int r{ 0 };
int fNode;

void dfs(int s, int sum) {
	if (sum > r) {
		r = sum;
		fNode = s;
	}
	for (int i{ 0 }; i < (int)vec[s].size(); ++i) {
		if (ch[vec[s][i].first] == 0) {
			ch[vec[s][i].first] = 1;
			dfs(vec[s][i].first, sum + vec[s][i].second);
			ch[vec[s][i].first] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b, c;
	for (int i{ 0 }; i < n; ++i) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)
				break;
			cin >> c;
			vec[a].push_back({ b,c });
		}		
	}
	ch[1] = 1;
	dfs(1, 0);
	memset(ch, 0, sizeof(ch));
	ch[fNode] = 1;
	dfs(fNode, 0);
	cout << r;
}
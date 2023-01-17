#include <iostream>
#include <string>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;


int ans[MAX]{};

int main() {
	ios_base::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	int jump[3]{ 2,-1,1 };
	queue<int> Q;
	Q.push(x);
	ans[x] = 1;
	while (!Q.empty()) {
		int a{ Q.front() };
		Q.pop();
		for (int i{ 0 }; i < 3; ++i) {
			int nx;
			if (i == 0) {
				nx = a * 2;
			}
			else {
				nx = a + jump[i];
			}

			if (nx < 0 || nx > 100000)
				continue;
			if (ans[nx] == 0) {
				Q.push(nx);
				if (i == 0) {
					ans[nx] = ans[a];
				}
				else {
					ans[nx] = ans[a] + 1;
				}
			}
			if (nx == y) {
				cout << ans[nx] - 1;
				return 0;
			}
		}

	}
}
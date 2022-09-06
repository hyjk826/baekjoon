#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k;
	int xx[]{ -1,1,2 };
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	int map[100001]{};
	int dis[100001]{};
	queue<int> Q;
	dis[n] = 0;
	Q.push(n);
	while (!Q.empty()) {
		int x{ Q.front() };
		Q.pop();
		int next_x;
		for (int i{ 0 }; i < 3; ++i) {
			if (i < 2) {
				next_x = x + xx[i];
			}
			if (i == 2) {
				next_x = x * xx[i];
			}
			if (next_x < 0 || next_x > 100000)
				continue;
			if (next_x == k) {
				cout << dis[x] + 1;
				return 0;
			}
			if (dis[next_x] == 0 && next_x != n) {
				Q.push(next_x);
				dis[next_x] = dis[x] + 1;
			}
		}
	}
}

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 2147000000

int map[128][128];
int white{ 0 };
int blue{ 0 };

int check(int s, int x, int y) {
	for (int i{ x }; i < x + s; ++i) {
		for (int j{ y }; j < y + s; ++j) {
			if (map[i][j] != map[x][y]) {
				return false;
			}
		}
	}
	return true;
}

void recur(int s, int x, int y) {
	if (check(s, x, y)) {
		if (map[x][y] == 0) {
			white++;
		}
		else if (map[x][y] == 1) {
			blue++;
		}
	}
	else {
		recur(s / 2, x, y);
		recur(s / 2, x, y + s / 2);
		recur(s / 2, x + s / 2, y);
		recur(s / 2, x + s / 2, y + s / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	recur(n, 0, 0);
	cout << white << "\n";
	cout << blue;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
vector<char> ch(16, 'z');
char ans[16];
int visited[30]{};
int a{ 0 };
int b{ 0 };

void DFS(int L) {
	if (L == l) {
		for (int i{ 0 }; i < l; ++i) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				a++;
			else
				b++;
			if (a >= 1 && b >= 2) {
				for (int i{ 0 }; i < l; ++i) {
					cout << ans[i];
				}
				cout << "\n";
				break;
			}
		}
		a = b = 0;	
	}
	else {
		if (L == 0) {
			for (int i{ 0 }; i < c; ++i) {
				if (visited[ch[i] - 'a'] == 0) {
					ans[L] = ch[i];
					visited[ch[i] - 'a'] = 1;
					DFS(L + 1);
					visited[ch[i] - 'a'] = 0;
				}
			}
		}
		else {
			for (int i{ 0 }; i < c; ++i) {
				if (visited[ch[i] - 'a'] == 0 && ch[i] > ans[L-1]) {
					ans[L] = ch[i];
					visited[ch[i] - 'a'] = 1;
					DFS(L + 1);
					visited[ch[i] - 'a'] = 0;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> l >> c;
	for (int i{ 0 }; i < c; ++i) {
		cin >> ch[i];
	}
	sort(ch.begin(), ch.end());
	DFS(0);
}
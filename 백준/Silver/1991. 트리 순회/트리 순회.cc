// 2022-09-06
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<int> vec[26];

void dfs1(int k) {
	if (k == '.' - 'A') return;
	cout << char(k + 'A');
	dfs1(vec[k][0]);
    dfs1(vec[k][1]);
}
void dfs2(int k) {
	if (k == '.' - 'A') return;
	dfs2(vec[k][0]);
	cout << char(k + 'A');
	dfs2(vec[k][1]);
}

void dfs3(int k) {
	if (k == '.' - 'A') return;
	dfs3(vec[k][0]);
    dfs3(vec[k][1]);
	cout << char(k + 'A');
}

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		vec[a - 'A'].push_back(b - 'A');
		vec[a - 'A'].push_back(c - 'A');
	}
	dfs1(0);
	cout << "\n";
	dfs2(0);
	cout << "\n";
	dfs3(0);
} 


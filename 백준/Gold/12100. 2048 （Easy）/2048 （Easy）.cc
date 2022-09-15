// 2022-09-15
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

int n;
int ans{ 0 };
vector<vi> vec;

void dfs(int L) {
	if (L == 5) {
		 for (int i{ 0 }; i < n; ++i) {
			for (int j{ 0 }; j < n; ++j) {
				ans = max(ans, vec[i][j]);
			}
		}
	}
	else {
		vector<vi> c(n, vi(n));
		c = vec;
		for (int i{ 0 }; i < n; ++i) {
			for (int j{ 0 }; j < n; ++j) {
				c[i][j] = vec[i][j];
			}
		}
		for (int a{ 0 }; a < 4; ++a) {
			if (a == 0) { // 왼쪽
				for (int i{ 0 }; i < n; ++i) {
					vector<int> v;
					for (int j{ 0 }; j < n; ++j) {
						if (vec[i][j] > 0) v.push_back(vec[i][j]);
					}
					vector<int> v2;
					for (int j{ 0 }; j < (int)v.size(); ++j) {
						if (j == v.size() - 1) {
							v2.push_back(v[j]);
							break;
						}
						if (v[j] == v[j + 1]) {
							v2.push_back(v[j] * 2);
							++j;
						}
						else v2.push_back(v[j]);
					}
					for (int j{ 0 }; j < (int)v2.size(); ++j) {
						vec[i][j] = v2[j];
					}
					for (int j{ (int)v2.size() }; j < n; ++j) {
						vec[i][j] = 0;
					}
				}
			}
			else if (a == 1) { // 오른쪽
				for (int i{ 0 }; i < n; ++i) {
					vector<int> v;
					for (int j{ n - 1 }; j >= 0; --j) {
						if (vec[i][j] > 0) v.push_back(vec[i][j]);
					}
					vector<int> v2;
					for (int j{ 0 }; j < (int)v.size(); ++j) {
						if (j == v.size() - 1) {
							v2.push_back(v[j]);
							break;
						}
						if (v[j] == v[j + 1]) {
							v2.push_back(v[j] * 2);
							++j;
						}
						else v2.push_back(v[j]);
					}
					for (int j{ 0 }; j < (int)v2.size(); ++j) {
						vec[i][n - 1 - j] = v2[j];
					}
					for (int j{ 0 }; j < n - (int)v2.size(); ++j) {
						vec[i][j] = 0;
					}
				}
			}
			else if (a == 2) { // 아래
				for (int i{ 0 }; i < n; ++i) {
					vector<int> v;
					for (int j{ n - 1 }; j >= 0; --j) {
						if (vec[j][i] > 0) v.push_back(vec[j][i]);
					}
					vector<int> v2;
					for (int j{ 0 }; j < (int)v.size(); ++j) {
						if (j == v.size() - 1) {
							v2.push_back(v[j]);
							break;
						}
						if (v[j] == v[j + 1]) {
							v2.push_back(v[j] * 2);
							++j;
						}
						else v2.push_back(v[j]);
					}
					for (int j{ 0 }; j < (int)v2.size(); ++j) {
						vec[n - 1 - j][i] = v2[j];
					}
					for (int j{ 0 }; j < n - (int)v2.size(); ++j) {
						vec[j][i] = 0;
					}
				}
			}
			else { // 위
				for (int i{ 0 }; i < n; ++i) {
					vector<int> v;
					for (int j{ 0 }; j < n; ++j) {
						if (vec[j][i] > 0) v.push_back(vec[j][i]);
					}
					vector<int> v2;
					for (int j{ 0 }; j < (int)v.size(); ++j) {
						if (j == v.size() - 1) {
							v2.push_back(v[j]);
							break;
						}
						if (v[j] == v[j + 1]) {
							v2.push_back(v[j] * 2);
							++j;
						}
						else v2.push_back(v[j]);
					}
					for (int j{ 0 }; j < (int)v2.size(); ++j) {
						vec[j][i] = v2[j];
					}
					for (int j{ 0 }; j < n - (int)v2.size(); ++j) {
						vec[n - 1 - j][i] = 0;
					}
				}
			}
			dfs(L + 1);
			vec = c;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vec.resize(n, vi(n));
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < n; ++j) {
			cin >> vec[i][j];
		}
	}
	dfs(0);
	cout << ans;
}
	


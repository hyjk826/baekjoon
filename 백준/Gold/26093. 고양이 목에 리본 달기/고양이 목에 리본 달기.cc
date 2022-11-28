// 2022-11-27
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;


int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	vector<vi> board(n, vi(k));
	int ans{0};
	for(int i{0}; i < n; ++i){
		for(int j{0}; j < k; ++j){
			cin >> board[i][j];
		}
	}
	vi pre(k);
	vi post(k);
	pre[0] = board[0][0];
	post[k - 1] = board[0][k - 1];
	for(int i{1}; i < k; ++i){
		pre[i] = max(pre[i - 1], board[0][i]);
	}
	for(int i{k - 2}; i >= 0; --i){
		post[i] = max(post[i + 1], board[0][i]);
	}
	for(int i{1}; i < n; ++i){
		for(int j{0}; j < k; ++j){
			if(j == 0) board[i][j] += post[j + 1];
			else if(j == k - 1) board[i][j] += pre[j - 1];
			else board[i][j] += max(pre[j - 1], post[j + 1]);
		}
		pre[0] = board[i][0];
		post[k - 1] = board[i][k - 1];
		for(int j{1}; j < k; ++j){
			pre[j] = max(pre[j - 1], board[i][j]);
		}
		for(int j{k - 2}; j >= 0; --j){
			post[j] = max(post[j + 1], board[i][j]);
		}		
	}
	for(int j{0}; j < k; ++j){
		ans = max(ans, board[n - 1][j]);
	}
	cout << ans;
}
	

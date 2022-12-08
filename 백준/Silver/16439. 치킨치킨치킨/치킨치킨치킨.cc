// 2022-12-08
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
	int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    for(int i{0}; i < m; ++i){
        int sum{0};
        for(int j{0}; j < n; ++j){
            sum += board[j][i];
        }
        ans = max(ans, sum);
    }
    for(int i{0}; i < m; ++i){
        for(int j{i + 1}; j < m; ++j){
            int sum{0};
            for(int k{0}; k < n; ++k){
                sum += max(board[k][i], board[k][j]);
            }
            ans = max(ans, sum);
        }
    }
    for(int i{0}; i < m; ++i){
        for(int j{i + 1}; j < m; ++j){
            for(int k{j + 1}; k < m; ++k){
                int sum{0};
                for(int l{0}; l < n; ++l){
                    sum += max({board[l][i],board[l][j], board[l][k]});
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans;
}
	

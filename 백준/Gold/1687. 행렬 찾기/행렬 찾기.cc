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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{1}; i <= n; ++i){
            board[i][j] += board[i - 1][j];
        }
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        for(int j{i}; j <= n; ++j){
            vi A;
            A.push_back(0);
            for(int k{1}; k <= m; ++k){
                if(board[j][k] - board[i - 1][k] > 0) A.push_back(k);
            }
            A.push_back(m + 1);
            int mx{0};
            for(int k{1}; k < (int)A.size(); ++k){
                mx = max(mx, A[k] - A[k - 1]);
            }
            if(mx){
                ans = max(ans, (mx - 1) * (j - i + 1));
            }
        }
    }
    cout << ans;
}

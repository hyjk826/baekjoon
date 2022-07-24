// 2022-07-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{min(n, m)}; i >= 1; --i){
        for(int j{0}; j <= n - i; ++j){
            for(int k{0}; k <= m - i; ++k){
                int a = board[j][k];
                if(a == board[j + i - 1][k] && a == board[j][k + i - 1] && a == board[j + i - 1][k + i - 1]){
                    cout << i * i;
                    return 0;
                }
            }
        }
    }
}


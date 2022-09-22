// 2022-09-21
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

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int ans{MAX};
    for(int i{0}; i < (1 << (2 * n)); ++i){
        vector<vi> copy;
        copy = board;
        int cnt = __builtin_popcount(i);
        for(int j{0}; j < 2 * n; ++j){
            if((i >> j) & 1){
                if(j < n){
                    for(int a{0}; a < n; ++a){
                        copy[a][j] ^= 1;
                    }
                }
                else{
                    for(int a{0}; a < n; ++a){
                        copy[j - n][a] ^= 1;
                    }
                }
            }
        }
        int sum{0};
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < n; ++k){
                if(copy[j][k]) sum++;
            }
        }
        ans = min(ans, cnt + min(sum, n * n - sum));
    }
    cout << ans;
}
	


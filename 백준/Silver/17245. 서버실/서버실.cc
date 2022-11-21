// 2022-11-21
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
	int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    ll sum{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            sum += board[i][j];
        }
    }
    int l{0}, r{(int)1e7};
    int ans{MAX};
    while(l <= r){
        int m{(l + r) / 2};
        ll k{0};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                k += min(board[i][j], m);
            }
        }
        if(k >= (sum + 1) / 2){
            r = m - 1;
            ans = m;
        }
        else l = m + 1;
    }
    cout << ans;
}
	


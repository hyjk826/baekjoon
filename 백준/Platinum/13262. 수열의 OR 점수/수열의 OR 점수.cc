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

const int sz = 5e3 + 10;

int ch[sz][sz];
int vec[sz];
ll dp[sz][sz];
int n, m;

int C(int i, int j){
    return ch[i][j];
}


void f(int i, int l, int r, int s, int e){
    if(l > r) return;
    int mid = (l + r) >> 1;
    int pos = -1;
    for(int j{s}; j <= min(mid, e); ++j){
        int c = C(j + 1, mid);
        if(dp[i - 1][j] + c > dp[i][mid]){
            dp[i][mid] = dp[i - 1][j] + c;
            pos = j;
        }
    }
    f(i, l, mid - 1, s, pos);
    f(i, mid + 1, r, pos, e);
}



void solve(){
	cin >> n >> m;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    for(int i{1}; i <= n; ++i){
        int k = 0;
        for(int j{i}; j <= n; ++j){
            k |= vec[j];
            ch[i][j] = k;
        }
    }
    for(int i{1}; i <= n; ++i){
        dp[1][i] = C(1, i);
    }
    for(int i{2}; i <= m; ++i){
        f(i, 1, n, 1, n);
    }
    cout << dp[m][n] << '\n';
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
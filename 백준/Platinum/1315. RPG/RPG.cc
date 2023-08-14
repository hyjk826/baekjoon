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

void solve(){
	int n;
    cin >> n;
    vector<vi> board(n, vi(3));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(1001, vi(1001, -1));
    vi ch(n);
    function<int(int,int)> f = [&](int a, int b){
        int& ret = dp[a][b];
        if(ret != -1) return ret;
        int p{0};
        ret = 0;
        vi tmp;
        for(int i{0}; i < n; ++i){
            if(a >= board[i][0] || b >= board[i][1]){
                ret++;
                if(ch[i]) continue;
                ch[i] = 1;
                p += board[i][2];
                tmp.push_back(i);
            }
        }
        for(int i{0}; i <= p; ++i){
            ret = max(ret, f(min(1000, a + i), min(1000, b + p - i)));
        }
        for(auto& i : tmp) ch[i] = 0;
        return ret;
    };
    cout << f(1, 1) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

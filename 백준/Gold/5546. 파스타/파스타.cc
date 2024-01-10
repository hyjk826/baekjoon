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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n, k;
    cin >> n >> k;
    int dp[101][4][4];
    memset(dp, -1, sizeof(dp));
    vi ch(n + 1);
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        ch[a] = b;
    }
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(a == n + 1) return 1;
        if(dp[a][b][c] != -1) return dp[a][b][c];
        int& ret = dp[a][b][c];
        ret = 0;
        if(ch[a]){
            if(!(b == c && b == ch[a])) ret += f(a + 1, c, ch[a]);
        } 
        else{
            for(int i{1}; i <= 3; ++i){
                if(b == c && b == i) continue;                
                ret += f(a + 1, c, i);
            }
        }
        ret %= 10000;
        return ret;
    };
    cout << f(1, 0, 0) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

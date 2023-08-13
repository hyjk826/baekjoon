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
    string s, t;
    cin >> s >> t;
    vector<vi> dp(n, vi(10, -1));
    vector<vi> ch(n, vi(10, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a >= n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        int x = s[a] - '0';
        int y = t[a] - '0';
        x = (x + b) % 10;
        int k = (y - x + 10) % 10;
        int q = f(a + 1, (b + k) % 10);
        int w = f(a + 1, b % 10);
        if(q + k <= 10 - k + w){
            ch[a][b] = k;
            ret = k + q;
        }
        else{
            ch[a][b] = k - 10;
            ret = -ch[a][b] + w;
        }
        return ret;
    };
    cout << f(0, 0) << "\n";
    int x{0}, y{0};
    while(x != n){
        if(ch[x][y] != 0) cout << x + 1 << " " << ch[x][y] << "\n";
        if(ch[x][y] >= 0) y = (y + ch[x][y] + 10) % 10;        
        x++;
    }
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

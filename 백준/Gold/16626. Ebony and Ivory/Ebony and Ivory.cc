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

int ch[4][5][5][13];
int ch2[12];

void solve(){
    ch2[0] = ch2[2] = ch2[5] = ch2[7] = ch2[10] = 1;
	vi w(4);
    int n;
    for(int i{0}; i < 4; ++i) cin >> w[i];
    for(int i{0}; i < 4; ++i){
        for(int j{0}; j < 5; ++j){
            for(int k{0}; k < 5; ++k){
                for(int a{0}; a < 13; ++a){
                    ch[i][j][k][a] = (int)1e9;
                }
            }
        }
    }
    cin >> n;
    for(int i{0}; i < 4; ++i){
        for(int j{0}; j < w[i]; ++j){
            int a, b;
            cin >> a >> b;
            a--; b--;
            for(int k{1}; k <= 12; ++k){
                cin >> ch[i][a][b][k];
            }
        }
    }
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vector<vi> dp(n, vi(5, -1));
    function<int(int,int)> f = [&](int a, int b){        
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        if(a == 0) return ret = 0;
        else{
            if(vec[a] == vec[a - 1]) return ret = f(a - 1, b);
            else {
                ret = MAX;
                for(int i{0}; i < 5; ++i){
                    int x, y;
                    x = y = 0;
                    if(ch2[vec[a - 1] % 12]) x = 1;
                    if(ch2[vec[a] % 12]) y = 1;
                    int q = i;
                    int w = b;
                    if(vec[a - 1] > vec[a]) {
                        swap(x, y);
                        swap(q, w);
                    }
                    ret = min(ret, f(a - 1, i) + ch[x << 1 | y][q][w][abs(vec[a] - vec[a - 1])]);
                }
            }
        }
        return ret;
    };
    int ans{MAX};
    for(int i{0}; i < 5; ++i){
        ans = min(ans, f(n - 1, i));
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
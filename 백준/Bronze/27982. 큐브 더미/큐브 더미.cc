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

int ch[7][7][7];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        ch[a][b][c] = 1;
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            for(int k{1}; k <= n; ++k){
                if(ch[i][j][k] == 0) continue;
                bool ok = true;
                for(int a{-1}; a <= 1; ++a){
                    ok &= (ch[i + a][j][k] == 1);
                    ok &= (ch[i][j + a][k] == 1);
                    ok &= (ch[i][j][k + a] == 1);
                }
                if(ok) ans++;
            }
        }
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

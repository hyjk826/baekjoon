#include <bits/stdc++.h>
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
	int n, m;
    cin >> n >> m;
    vp vec(m + 1);
    for(int i{1}; i <= m; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vector<vi> dp(m + 1, vi(m + 1, -1));
    vector<vi> ch(m + 1, vi(m + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == m || b == m) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int x1, y1, x2, y2;
        if(a == 0) {
            x1 = y1 = 1;
        }
        else{
            x1 = vec[a].first; y1 = vec[a].second;
        }
        if(b == 0){
            x2 = y2 = n;
        }
        else{
            x2 = vec[b].first; y2 = vec[b].second;
        }
        int next = max(a, b) + 1;
        int first = f(next, b) + abs(vec[next].first - x1) + abs(vec[next].second - y1);
        int second = f(a, next) + abs(vec[next].first - x2) + abs(vec[next].second - y2);
        if(first <= second){
            ch[a][b] = 1;
            dp[a][b] = first;
        }
        else{
            ch[a][b] = 2;
            dp[a][b] = second;
        }
        return dp[a][b];
    };
    cout << f(0, 0) << "\n";
    int x, y;
    x = y = 0;
    while(x != m && y != m){
        if(ch[x][y] == 1){
            cout << 1 << "\n";
            x = max(x, y) + 1;
        }
        else{
            cout << 2 << "\n";
            y = max(x, y) + 1;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
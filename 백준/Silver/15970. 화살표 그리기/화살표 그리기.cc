// 2022-08-19
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi g[5001];

int main(){
    fastio;
	int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    ll ans{0};
    for(int i{1}; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
        for(int j{0}; j < (int)g[i].size(); ++j){
            int a = j - 1;
            int b = j + 1;
            int mn{MAX};
            if(a >= 0) mn = min(mn, g[i][j] - g[i][a]);
            if(b < (int)g[i].size()) mn = min(mn, g[i][b] - g[i][j]);
            if(mn == MAX) continue;
            ans += mn;
        }
    }
    cout << ans;
}
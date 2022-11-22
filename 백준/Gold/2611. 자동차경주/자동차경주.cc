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

int n, m;
vector<vp> g;
vi dp(1001, -1);
vi p(1001, -1);

int f(int a){
    if(dp[a] != -1) return dp[a];
    dp[a] = 0;
    int mx{0};
    int idx{-1};
    for(auto& i : g[a]){
        if(i.first == 1){
            if(dp[a] < i.second){
                dp[a] = mx = i.second;
                idx = i.first;
                p[a] = i.first;
            }
        }
        else{
            if(dp[a] < i.second + f(i.first)){
                dp[a] = mx = i.second + f(i.first);
                idx = i.first;
                p[a] = i.first;
            }
        }
    }
    return dp[a];
}

int main() {
	fastio;		
    cin >> n >> m;    
    g.resize(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[b].push_back({a, c});
    }
    cout << f(1) << "\n";
    vi ans;
    ans.push_back(1);
    int k = p[1];
    while(k != 1){
        ans.push_back(k);
        k = p[k];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(auto& i : ans){
        cout << i << " ";
    }
}
	


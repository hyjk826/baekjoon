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

int main(){
	fastio;
    int n, s, d;
    cin >> n >> s >> d;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt{0};
    vi ch(n + 1);
    vi mx(n + 1, MAX);
    function<void(int,int)> dfs = [&](int cur, int pre){
        mx[cur] = 0;        
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
            mx[cur] = max(mx[cur], mx[i] + 1);
        }
    };
    dfs(s, -1);
    function<void(int,int)> dfs2 = [&](int cur, int pre){
        for(auto& i : g[cur]){
            if(mx[i] < d) continue;
            if(i == pre) continue;
            cnt++;
            dfs2(i, cur);
            cnt++;
        }
    };
    dfs2(s, -1);
    cout << cnt;
}

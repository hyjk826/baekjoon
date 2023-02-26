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

const int sz = 1e6 + 10;

int id{0};
int d[sz]{}; 
int sccNum; 
int sn[sz]; 
vector<int> g[sz];
bool finished[sz]; 
stack<int> s;

int dfs(int c) {
	d[c] = ++id; 
	s.push(c); 
	int result = d[c];
	for (int next : g[c]) {
		if (d[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, d[next]);
	}
	if (result == d[c]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		} 
		sccNum++;
	}
	return result;
}


int g2[sz];
int cnt[sz];
int dp[sz];

int f(int a){
    if(a == -1) return 0;
    if(dp[a] != -1) return dp[a];
    dp[a] = cnt[a] + f(g2[a]);
    return dp[a];
}

int main(){
	fastio;
    int m, n;
    cin >> m >> n;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i{0}; i < n; ++i){
        if(d[i] == 0) dfs(i);
    }
    memset(g2, -1, sizeof(g2));
    memset(dp, -1, sizeof(dp));
    for(int i{0}; i < n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]) g2[sn[i]] = sn[j];
        }
        cnt[sn[i]]++;
    }
    int ans{0};
    for(int i{0}; i < sccNum; ++i){
        ans = max(ans, f(i));
    }
    cout << ans;
}

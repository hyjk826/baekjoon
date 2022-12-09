// 2022-12-08
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

int id{0};
int d[500001]{}; 
int sccNum; 
int sn[500001]; 
vector<int> g[500001];
bool finished[500001]; 
stack<int> s;
vector<vector<int>> SCC;

int dfs(int c) {
	d[c] = ++id; 
	s.push(c); 
	int result = d[c];
	for (int next : g[c]) {
		if (d[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, d[next]);
	}

	if (result == d[c]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc); 
		sccNum++;
	}
	return result;
}

int S, p;
vector<vi> g2;
vl B;
vl dp;

ll f(int a){
    if(dp[a] != -1) return dp[a];
    if(a == sn[S]) return dp[a] = B[a];
    if(g2[a].size() == 0){
        return dp[a] = -LLONG_MAX;
    }
    dp[a] = B[a];
    ll mx{-LLONG_MAX};
    for(auto& i : g2[a]){
        mx = max(mx, f(i));
    }
    dp[a] += mx;
    return dp[a];
}

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{1}; i <= n; ++i){
        if(d[i] == 0) dfs(i);
    }
    g2.resize(sccNum);
    B.resize(sccNum);
    dp.resize(sccNum, -1);
    for(int i{1}; i <= n; ++i){
        B[sn[i]] += A[i];
    }   
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]){
                g2[sn[j]].push_back(sn[i]);
            }
        }
    }
    cin >> S >> p;
    vi P(p);
    for(int i{0}; i < p; ++i) cin >> P[i];
    ll ans{0};
    for(int i{0}; i < p; ++i){
        ans = max(ans, f(sn[P[i]]));
    }
    cout << ans;
}
	

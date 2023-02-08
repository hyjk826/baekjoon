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

const int sz = 2e5 + 10;

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
        int cnt{0};
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

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int sum{0};
        int a = i + 1;
        while(a){
            sum += a % 10;
            a /= 10;
        }
        g[i].push_back((i + sum) % n);
    }
    for(int i{0}; i < n; ++i){
        if(d[i] == 0) dfs(i);
    }
    vi cnt(sccNum);
    for(int i{0}; i < n; ++i){
        cnt[sn[i]]++;
    }
    vector<vi> g2(sccNum);
    for(int i{0}; i < n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]){
                g2[sn[i]].push_back(sn[j]);
            }   
        }
    }
    vi dp(sccNum, -1);
    function<int(int)> f = [&](int cur){
        if(dp[cur] != -1) return dp[cur];
        dp[cur] = cnt[cur];
        for(auto& i : g2[cur]){
            dp[cur] += f(i);
        }
        return dp[cur];
    };
    int ans{0};
    for(int i{0}; i < sccNum; ++i){
        ans = max(ans, f(i));
    }
    cout << ans;
}

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

struct st{
    int v; ll w;
    bool operator< (const st a) const{
        return w < a.w;
    }
};


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
    vector<vi> g2(sccNum);
    vl B(sccNum);
    for(int i{1}; i <= n; ++i){
        B[sn[i]] += A[i];
    }   
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]){
                g2[sn[i]].push_back(sn[j]);
            }
        }
    }
    int S, p;
    cin >> S >> p;
    vi ch(sccNum);
    for(int i{0}; i < p; ++i){
        int a;
        cin >> a;
        ch[sn[a]] = 1;
    }
    ll ans{0};
    priority_queue<st> pQ;
    pQ.push({sn[S], B[sn[S]]});
    vl dijk(sccNum, -LLONG_MAX);
    dijk[sn[S]] = B[sn[S]];
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v] > w) continue;
        for(auto& i : g2[v]){
            if(dijk[i] < w + B[i]){
                dijk[i] = w + B[i];
                pQ.push({i, w + B[i]});
            }
        }
    }
    for(int i{0}; i < sccNum; ++i){
        if(ch[i] == 0) continue;
        ans = max(ans, dijk[i]);
    }
    cout << ans;
}
	

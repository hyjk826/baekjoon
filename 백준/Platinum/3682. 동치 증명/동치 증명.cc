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

const int sz = 2e4 + 10;

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

void init(int n){
    for(int i{1}; i <= n; ++i){
        g[i].clear();
        sn[i] = finished[i] = d[i] = 0;
    }
    sccNum = id = 0;
}

void solve(){
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i{1}; i <= n; ++i){
        if(d[i] == 0) dfs(i);
    }
    if(sccNum == 1){
        cout << 0 << "\n"; return;
    }
    vi indegree(sccNum), outdegree(sccNum);
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]){
                indegree[sn[j]]++;
                outdegree[sn[i]]++;
            }
        }
    }
    int a{0}, b{0};
    for(auto& i : indegree){
        if(i == 0) a++;
    }
    for(auto& i : outdegree){
        if(i == 0) b++;
    }
    cout << max(a, b) << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}

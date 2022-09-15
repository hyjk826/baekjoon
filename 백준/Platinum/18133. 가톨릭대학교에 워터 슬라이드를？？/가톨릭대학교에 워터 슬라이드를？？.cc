// 2022-09-15
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int id{0};
int d[100001]{}; 
int sccNum; 
int sn[100001]; 
vector<int> graph[100001];
bool finished[100001]; 
stack<int> s;
vector<vector<int>> SCC;

int dfs(int c) {
	d[c] = ++id;
	s.push(c); 

	int result = d[c];
	for (int next : graph[c]) {		
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

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i{1}; i <= n; ++i){
        if(d[i] == 0){
            dfs(i);
        }
    }
    vi degree((int)SCC.size());
    for(int i{1}; i <= n; ++i){
        for(auto& j : graph[i]){
            if(sn[i] == sn[j]) continue;
            degree[sn[j]]++;
        }
    }
    int ans{0};
    for(auto& i : degree){
        if(i == 0) ans++;
    }
    cout << ans;
}



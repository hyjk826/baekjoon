// 2023-01-25
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

const int sz = 5e3 + 10;

int id{0};
int d[sz]{}; 
int sccNum; 
int sn[sz]; 
vector<int> g[sz];
bool finished[sz]; 
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

int n, m;

void init(){
    sccNum = 0;
    SCC.clear();
    for(int i{1}; i <= n; ++i){
        d[i] = sn[i] = finished[i] = 0;
        g[i].clear();
    }
}

int main(){
	fastio;
    while(cin >> n >> m){
        init();
        for(int i{0}; i < m; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        for(int i{1}; i <= n; ++i){
            if(d[i] == 0) dfs(i);
        }
        vi degree(sccNum);
        for(int i{1}; i <= n; ++i){
            for(auto& j : g[i]){
                if(sn[i] != sn[j]){
                    degree[sn[i]]++;
                }
            }
        }
        for(int i{1}; i <= n; ++i){
            if(degree[sn[i]] == 0) cout << i << " ";
        }
        cout << "\n";
    }
}

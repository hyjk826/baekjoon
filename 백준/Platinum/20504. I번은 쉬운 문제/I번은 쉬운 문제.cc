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
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
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
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i{1}; i <= n; ++i){
        if(d[i] == 0) dfs(i);
    }
    vector<vi> g2(sccNum);
    vi degree(sccNum);
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]){
                g2[sn[i]].push_back(sn[j]);
                degree[sn[j]]++;
            }
        }
    }
    vi ch(sccNum);
    int tt;
    cin >> tt;
    while(tt--){
        int a;
        cin >> a;
        ch[sn[a]] = 1;
    }
    int ans{0};
    for(int i{0}; i < sccNum; ++i){
        if(degree[i] == 0){
            if(ch[i] == 0){
                cout << -1; return 0;
            }
            ans++;
        }
    }
    cout << ans;
}

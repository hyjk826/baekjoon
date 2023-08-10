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

const int sz = 3e2 + 10;

int n;
int id{0};
int d[sz]{}; 
int sccNum; 
int sn[sz]; 
vector<int> g[sz];
bool finished[sz]; 
stack<int> s;

void init(){
	for(int i{0}; i <= n; ++i){
		d[i] = sn[i] = finished[i] = 0;
		g[i].clear();		
	}
	id = sccNum = 0;
}

int dfs(int c) {
	d[c] = ++id; 
	s.push(c); 
	int mn = d[c];
	for (int next : g[c]) {
		if (d[next] == 0) mn = min(mn, dfs(next));
		else if (!finished[next]) mn = min(mn, d[next]);
	}
	if (mn == d[c]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		} 
		sccNum++;
	}
	return mn;
}

void solve(){
    cin >> n;
    init();
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char c;
            cin >> c;
            if(i != j && c == '1') board[i][j] = 1;
        }
    }
    for(int k{0}; k < n; ++k){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                if(board[i][k] && board[k][j] && board[i][j]) board[i][j] = 0;
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j]) g[i].push_back(j);
        }
    }
    for(int i{0}; i < n; ++i){
        if(d[i] == 0) dfs(i);
    }
    vector<vi> S(sccNum);
    vp ans;
    for(int i{0}; i < n; ++i){
        S[sn[i]].push_back(i);
        for(auto& j : g[i]){
            if(sn[j] != sn[i]) ans.push_back({i, j});
        }
    }
    for(int i{0}; i < sccNum; ++i){
        if(S[i].size() == 1) continue;
        for(int j{0}; j < (int)S[i].size(); ++j){
            ans.push_back({S[i][j], S[i][(j + 1) % (int)S[i].size()]});
        }
    }
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
}  

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
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

const int sz = 5e5 + 10;
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

int n, m;

int inv(int x){
    if(x >= 5 * n) return x - 5 * n;
    else return x + 5 * n;
}

void addEdge(int a, int b){
    g[a].push_back(b);
}

void addCNF(int a, int b){
    addEdge(inv(a), b);
    addEdge(inv(b), a);
}


void solve(){
	cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    cin >> m;
    for(int i{0}; i < m; ++i){
        char op;
        cin >> op;
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if(op == '&') {
            for(int j{0}; j < 5; ++j){
                if((c >> j) & 1) {
                    addCNF(a * 5 + j, a * 5 + j);
                    addCNF(b * 5 + j, b * 5 + j);
                } 
                else{                    
                    addEdge(a * 5 + j, inv(b * 5 + j));
                    addEdge(b * 5 + j, inv(a * 5 + j));
                }
            }            
        }
        else{
            for(int j{0}; j < 5; ++j){
                if((c >> j) & 1) {
                    addEdge(inv(a * 5 + j), b * 5 + j);
                    addEdge(inv(b * 5 + j), a * 5 + j);
                } 
                else{                    
                    addCNF(inv(a * 5 + j), inv(a * 5 + j));
                    addCNF(inv(b * 5 + j), inv(b * 5 + j));
                }
            }        
        }
    }
    for(int i{0}; i < n; ++i){
        if(vec[i]){
            for(int j{0}; j < 5; ++j){
                if((vec[i] >> j) & 1){
                    addCNF(i * 5 + j, i * 5 + j);
                }
                else{
                    addCNF(inv(i * 5 + j), inv(i * 5 + j));
                }
            }
        }
        addEdge(i * 5 + 4, inv(i * 5 + 3));
        addEdge(inv(i * 5 + 4), i * 5 + 3);
        addEdge(i * 5 + 3, inv(i * 5 + 4));
        addEdge(inv(i * 5 + 3), i * 5 + 4);
        addEdge(i * 5 + 4, inv(i * 5 + 2));
        addEdge(i * 5 + 2, i * 5 + 3);
    } 
    for(int i{0}; i < 10 * n; ++i){
        if(d[i] == 0) dfs(i);
    }
    vi ans(n);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 5; ++j){
            if(sn[i * 5 + j] < sn[inv(i * 5 + j)]){
                ans[i] |= (1 << j);
            }
            else if(sn[i * 5 + j] == sn[inv(i * 5 + j)]){
                cout << 0 << "\n"; return;
            }
        }
    }
    cout << 1 << "\n";
    for(int i{0}; i < n; ++i){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

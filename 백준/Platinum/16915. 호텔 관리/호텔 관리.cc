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
    if(x & 1) return x - 1;
    else return x + 1;
}

void addEdge(int a, int b){
    g[a].push_back(b);
}

void addCNF(int a, int b){
    addEdge(inv(a), b);
    addEdge(inv(b), a);
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        for(int j{0}; j < a; ++j){
            int b;
            cin >> b;
            g[b].push_back(i);
        }
    }
    for(int i{1}; i <= n; ++i){
        int x = g[i][0] * 2;
        int y = g[i][1] * 2;
        if(A[i]){
            addCNF(inv(x), y);
            addCNF(x, inv(y));
        }
        else{
            addCNF(x, y);
            addCNF(inv(x), inv(y));
        }
    }
    for(int i{0}; i < 2 * m; ++i){
        if(d[i] == 0) dfs(i);
    }
    for(int i{0}; i < 2 * m; i += 2){
        if(sn[i] == sn[i + 1]){
            cout << 0; return 0;
        }
    }
    cout << 1;
}

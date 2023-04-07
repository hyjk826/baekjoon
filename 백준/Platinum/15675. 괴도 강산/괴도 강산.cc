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


const int sz = 1e5 + 10;
int id{0};
int d[sz]{};
int sccNum = 1; 
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
    if(x > n + m) return x - n - m;
    else return x + n + m;
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
    cin >> n >> m;
    vi ch(n + m + 1);
    for(int a{1}; a <= n; ++a){
        for(int b{n + 1}; b <= n + m; ++b){
            char c;
            cin >> c;
            if(c == '*'){
                addEdge(a, inv(b));
                addEdge(inv(a), b);
                addEdge(b, inv(a));
                addEdge(inv(b), a);
            }
            else if(c == '#'){
                addEdge(a, b);
                addEdge(inv(a), inv(b));
                addEdge(b, a);
                addEdge(inv(b), inv(a));
            }
        }
    }
    for(int i{1}; i <= 2 * (n + m); ++i){
        if(d[i] == 0) dfs(i);
    }
    for(int i{1}; i <= n + m; ++i){
        if(sn[i] == sn[inv(i)]){
            cout << 0; return 0;
        }
    }
    cout << 1;
}

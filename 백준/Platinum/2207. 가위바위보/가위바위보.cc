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


const int sz = 20000 + 10;
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
    if(x > m) return x - m;
    else return x + m;
}

void addEdge(int a, int b){
    g[a].push_back(b);
}

void addCNF(int a, int b){
    if(a < 0) a = inv(-a);
    if(b < 0) b = inv(-b);
    addEdge(inv(a), b);
    addEdge(inv(b), a);
}

int main(){
	fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
		int a, b;
		cin >> a >> b;
		addCNF(a, b);
	}
	for(int i{1}; i <= n; ++i){
		if(d[i] == 0) dfs(i);
	}
	for(int i{1}; i <= n; ++i){
		if(sn[i] == sn[inv(i)]){
			cout << "OTL";
			return 0;
		}
	}
	cout << "^_^";
}

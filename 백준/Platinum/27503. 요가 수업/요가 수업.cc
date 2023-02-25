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

const int sz = 1e6 + 10;
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

int n, m, c, k;

int inv(int x){
    if(x > n) return x - n;
    else return x + n;
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
    cin >> n >> m >> c >> k;
    vi ch(n + 1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        ch[a]++;
    }
    vi ch2(n + 1);
    for(int i{0}; i < c; ++i){
        int a, b;
        cin >> a >> b;
        ch2[a]++; ch2[b]++;
        addCNF(a, b);
    }
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 1 && ch2[i] == 0) addCNF(i, i);
    }
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        addCNF(inv(a), inv(b));
    }
    for(int i{1}; i <= 2 * n; ++i){
        if(d[i] == 0) dfs(i);
    }
    for(int i{1}; i <= n; ++i){
        if(sn[i] == sn[inv(i)]){
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}

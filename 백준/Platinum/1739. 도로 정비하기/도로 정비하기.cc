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

int n, m, k;

int inv(int x){
    if(x > n + m) return x - (n + m);
    else return x + (n + m);
}

void addEdge(int a, int b){
    g[a].push_back(b);
}

void addCNF(int a, int b){
    addEdge(inv(a), b);
    addEdge(inv(b), a);
}


void init(){
    sccNum = id = 0;
    for(int i{1}; i <= (n + m) * 2; ++i){
        d[i] = sn[i] = finished[i] = 0;
        g[i].clear();
    }
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        init();
        for(int i{0}; i < k; ++i){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if(a == c && b == d) continue;
            b += n; d += n;
            if(a == c){
                if(b < d) addCNF(a, a);
                else addCNF(inv(a), inv(a));
                continue;
            }
            if(b == d){
                if(a < c) addCNF(b, b);
                else addCNF(inv(b), inv(b));
                continue;
            }
            if(a > c && b > d){
                a = inv(a); b = inv(b);
                c = inv(c); d = inv(d);
            }
            else if(a < c && b > d){
                a = inv(a); c = inv(c);
            }
            else if(a > c && b < d){
                b = inv(b); d = inv(d);
            }
            addCNF(a, c);
            addCNF(a, b);
            addCNF(d, c);
            addCNF(d, b);
        }
        for(int i{1}; i <= 2 * (n + m); ++i){
            if(d[i] == 0) dfs(i);
        }
        bool ok = true;
        for(int i{1}; i <= n + m; ++i){
            if(sn[i] == sn[inv(i)]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}

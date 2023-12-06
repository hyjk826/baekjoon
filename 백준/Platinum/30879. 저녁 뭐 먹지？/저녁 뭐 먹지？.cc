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
int n = (int)1e5;

void init(){
	for(int i{0}; i <= 2 * n; ++i){
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

struct st{
    int a, b, idx;
};

void solve(){
    int q;
    cin >> q;
    vector<st> A;
    vi B;
    int cnt{-1};
    for(int i{0}; i < q; ++i){
        int op, a, b;
        cin >> op;
        if(op == 1) {
            cin >> a >> b;
            A.push_back({a, b, i});
            cnt++;
        }
        else {
            B.push_back(cnt);
        }
    }
    int l{0}, r{(int)A.size() - 1};
    int ans{MAX};
    while(l <= r){
        int mid{(l + r) >> 1};
        init();
        for(int i{0}; i <= mid; ++i){
            int a = A[i].a;
            int b = A[i].b;
            if(a < 0) a = abs(a) + n;
            if(b < 0) b = abs(b) + n;
            addCNF(a, b);
        }
        for(int i{1}; i <= 2 * n; ++i){
            if(d[i] == 0) dfs(i);
        }
        bool ok = true;
        for(int i{1}; i <= n; ++i){
            if(sn[i] == sn[inv(i)]){
                ok = false; break;
            }
        }
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    for(auto& i : B){
        if(i <= ans) cout << "YES DINNER\n";
        else cout << "NO DINNER\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

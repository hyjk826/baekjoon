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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

typedef pair<int, int> p;

const int SZ = 666;
struct MCMF{
	int s, t; //source, sink
	struct Edge{ int v, c, d, dual; };
	vector<Edge> g[SZ];
	void addEdge(int s, int e, int c, int d){
		g[s].push_back({e, c, d, (int)g[e].size()});
		g[e].push_back({s, 0, -d, (int)g[s].size()-1});
	}

	int dst[SZ], inq[SZ];
	bool spfa(){
		memset(dst, 0x3f, sizeof dst);
		memset(inq, 0, sizeof inq);
		queue<int> q; q.push(s); inq[s] = 1; dst[s] = 0;
		while(q.size()){
			int now = q.front(); q.pop(); inq[now] = 0;
			for(auto i : g[now]){
				if(i.c && dst[i.v] > dst[now] + i.d){
					dst[i.v] = dst[now] + i.d;
					if(!inq[i.v]) inq[i.v] = 1, q.push(i.v);
				}
			}
		}
		return dst[t] < 1e9;
	}

	int chk[SZ], work[SZ];

	int dfs(int now, int fl){
        chk[now] = 1;
        if(now == t) return fl;
        for(; work[now] < g[now].size(); work[now]++){
            auto &i = g[now][work[now]];
            if(!chk[i.v] && dst[i.v] == dst[now] + i.d && i.c){
                int ret = dfs(i.v, min(fl, i.c));
                if(ret){
                    i.c -= ret; g[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
	}
	p run(int _s, int _t){ //{cost, flow}
		s = _s, t = _t;
		int cst = 0, fl = 0;
		while(spfa()){
			memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
			int now = 0;
			while(now = dfs(s, 1e9)){
				cst += dst[t] * now;
				fl += now;
				memset(chk, 0, sizeof chk);
			}
		}
		return p(cst, fl);
	}
} mcmf;

void solve(){
	int n;
    cin >> n;
    vi A(n), H(n), L(n);
    int mx{0};
    int idx{-1};
    for(int i{0}; i < n; ++i){
        cin >> A[i];
        if(mx < A[i]){
            mx = A[i]; idx = i;
        }
    }
    for(int i{0}; i < n; ++i) cin >> H[i];
    for(int i{0}; i < n; ++i) cin >> L[i];
    int source = SZ - 2;
    int sink = SZ - 1;
    for(int i{0}; i < n; ++i){
        if(idx == i) mcmf.addEdge(source, i, L[i], H[i]);
        else mcmf.addEdge(source, i, L[i] - 1, H[i]);
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(A[i] > A[j]) mcmf.addEdge(i, j + n, 1, -(A[i] ^ A[j]));
        }
    }
    for(int i{0}; i < n; ++i){
        if(idx == i) continue;
        mcmf.addEdge(i + n, sink, 1, H[i]);
    }
    auto ans = mcmf.run(source, sink);
    cout << -ans.first << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

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

struct BCC{
    int n, id{0};
    vector<vi> V;
    vi E;
    vi d;
    stack<pi> st;
    BCC(vector<vi>& g){
        n = (int)g.size();
        V.resize(n); E.resize(n); d.resize(n); 
        for(int i{0}; i < n; ++i){ // 0-based
            if(!d[i]) dfs(i, -1, g);
        }
    }
    int dfs(int cur, int par, vector<vi>& g){
        d[cur] = ++id;
        int ret = d[cur];
        for(auto& i : g[cur]){
            if(i == par) continue;
            if(d[i] < d[cur]) st.push({cur, i});
            if(d[i]) ret = min(ret, d[i]);
            else{
                int tmp = dfs(i, cur, g);
                ret = min(ret, tmp);
                if(tmp >= d[cur]){
                    vi tmpV;
                    int a{0};              
                    while(1){
                        auto x = st.top();
                        a++;
                        tmpV.push_back(st.top().first);
                        tmpV.push_back(st.top().second);
                        st.pop();
                        if(x == make_pair(cur, i)) break;
                    }
                    sort(tmpV.begin(), tmpV.end());
                    tmpV.erase(unique(tmpV.begin(), tmpV.end()), tmpV.end());
                    V.push_back(tmpV);
                    E.push_back(a);
                }
            }
        }
        return ret;
    }
};

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BCC bcc(g);
    vi cnt(n);
    for(int i{0}; i < (int)bcc.V.size(); ++i){
        if(bcc.V[i].size() <= 2) continue;
        if(bcc.V[i].size() ^ bcc.E[i]){
            cout << "Not cactus\n"; return;
        }
        for(auto& j : bcc.V[i]) cnt[j]++;
    }
    for(int i{0}; i < n; ++i){
        if(cnt[i] >= 2){
            cout << "Not cactus\n"; return;
        }
    }
    cout << "Cactus\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
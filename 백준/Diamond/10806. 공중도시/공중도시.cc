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
    vector<vp> E;
    vi d;
    stack<pi> st;
    BCC(vector<vp>& g){
        n = (int)g.size();
        V.resize(n); E.resize(n); d.resize(n); 
        for(int i{0}; i < n; ++i){ // 0-based
            if(!d[i]) dfs(i, -1, g);
        }
    }
    int dfs(int cur, int par, vector<vp>& g){
        d[cur] = ++id;
        int ret = d[cur];
        for(auto& i : g[cur]){
            if(i.second == par) continue;
            if(d[i.first] < d[cur]) {
                st.push({cur, i.first});
            }
            if(d[i.first]) ret = min(ret, d[i.first]);
            else{
                int tmp = dfs(i.first, i.second, g);
                ret = min(ret, tmp);
                if(tmp >= d[cur]){
                    vi tmpV;
                    vp tmpE;                    
                    while(1){
                        tmpE.push_back(st.top());
                        tmpV.push_back(st.top().first);
                        tmpV.push_back(st.top().second);
                        st.pop();
                        if(tmpE.back() == make_pair(cur, i.first)) break;
                    }
                    sort(tmpV.begin(), tmpV.end());
                    tmpV.erase(unique(tmpV.begin(), tmpV.end()), tmpV.end());
                    V.push_back(tmpV);
                    E.push_back(tmpE);
                }
            }
        }
        return ret;
    }
};

const int sz = (int)1e5 + 10;
int p[sz];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a); b = find(b);
    if(a ^ b){
        p[a] = b;
        return true;
    }
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vp> g(n);
    int idx{0};
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;        
        g[a].push_back({b, idx});
        g[b].push_back({a, idx++});
    }
    iota(p, p + sz, 0);
    BCC bcc(g);
    vp tmp;
    for(auto& i : bcc.E){
        if(i.size() == 1) {
            tmp.push_back(i[0]);
            continue;
        }
        for(int j{0}; j < (int)i.size(); ++j){
            merge(i[j].first, i[j].second);
        }
    }
    // for(auto& i : bcc.V){
    //     for(auto& j : i) cout << j + 1 << " ";
    //     cout << "\n";
    // }
    vector<vi> g2(n);
    for(auto& i : tmp){
        int a = find(i.first);
        int b = find(i.second);
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
    int id{0};
    vi ch(n);
    function<void(int,int)> dfs = [&](int cur, int par){
        ch[cur] = ++id;
        for(auto& i : g2[cur]){
            if(i == par) continue;
            dfs(i, cur);
        }
    };
    for(int i{0}; i < n; ++i){
        if(g2[i].size() == 0) continue;
        if(!ch[i]) dfs(i, -1);
    }
    vi tmp2;
    for(int i{0}; i < n; ++i){
        if(g2[i].size() == 1) tmp2.push_back(i);
    }
    vp A;
    for(auto& i : tmp2){
        A.push_back({i, ch[i]});
    }
    vp ans;
    sort(A.begin(), A.end(), [&](pi& x, pi& y){
        return x.second < y.second;
    });
    int k = (int)A.size() / 2;
    for(int i{0}; i < k; ++i){
        ans.push_back({A[i].first, A[i + k].first});
    }
    if(A.size() & 1) ans.push_back({A.back().first, A[(int)A.size() - 2].first});
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
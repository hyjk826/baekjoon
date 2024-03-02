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

vector<vi> g(1000001);

struct BCC{
    int n, id{0};
    vector<vi> V;
    vector<vp> E;
    vi d, cnt;
    stack<pi> st;
    BCC(int n){
        V.resize(n); E.resize(n); d.resize(n); cnt.resize(n);
        for(int i{0}; i < n; ++i){ // 0-based
            if(!d[i]) dfs(i, -1);
            else cnt[i]++;
        }
    }
    int dfs(int cur, int par){
        d[cur] = ++id;
        int ret = d[cur];
        for(auto& i : g[cur]){
            if(i == par) continue;
            if(d[i] < d[cur]) st.push({cur, i});
            if(d[i]) ret = min(ret, d[i]);
            else{
                int tmp = dfs(i, cur);
                ret = min(ret, tmp);
                if(tmp >= d[cur]){
                    cnt[cur]++;
                    vi tmpV;
                    vp tmpE;                    
                    while(1){
                        tmpE.push_back(st.top());
                        tmpV.push_back(st.top().first);
                        tmpV.push_back(st.top().second);
                        st.pop();
                        if(tmpE.back() == make_pair(cur, i)) break;
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

int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};


void solve(){
	int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int cnt{0};
    int a{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == '.') continue;
            a++;
            for(int dir{0}; dir < 4; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(board[nx][ny] == '.') continue;
                g[i * n + j].push_back(nx * n + ny);
                cnt++;
            }
        }
    }
    int need = 2 * (a - 2);
    int k = cnt - need;
    vp ans;
    BCC tmp(n * n);
    vi ch(n * n);
    for(int i{0}; i < n * n; ++i){
        if(tmp.cnt[i] > 1){
            ch[i] = 1;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(ch[i * n + j]) continue;
            if(board[i][j] == '.') continue;
            int b{0};
            for(int dir{0}; dir < 4; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(board[nx][ny] == '.') continue;
                b++;
            }
            if(b * 2 == k) ans.push_back({i, j});
        }
    }
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
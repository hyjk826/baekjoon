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

struct st{
    int x1, y1, x2, y2;
};

struct st2{
    int x, y;
    ll w;
    bool operator< (const st2& a) const{
        return w > a.w;
    }
};

int n, m, q;
ll board[5][100000];
st query[100000];
ll ans[100000];
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};
ll dijk[5][100000];

void f(int l, int r, vi& v){
    if(l > r || v.empty()) return;        
    int mid{(l + r) >> 1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{l}; k <= r; ++k){
                dijk[j][k] = (ll)1e18;
            }
        }
        priority_queue<st2> pQ;
        pQ.push({i, mid, board[i][mid]});
        dijk[i][mid] = board[i][mid];
        while(!pQ.empty()){
            int x{pQ.top().x};
            int y{pQ.top().y};
            ll w{pQ.top().w};
            pQ.pop();
            if(dijk[x][y] < w) continue;
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < l || ny > r) continue;
                if(dijk[nx][ny] > dijk[x][y] + board[nx][ny]){
                    dijk[nx][ny] = dijk[x][y] + board[nx][ny];
                    pQ.push({nx, ny, dijk[nx][ny]});
                }
            }
        }
        for(auto& j : v){
            int x1 = query[j].x1; int y1 = query[j].y1;
            int x2 = query[j].x2; int y2 = query[j].y2;
            ans[j] = min(ans[j], dijk[x1][y1] + dijk[x2][y2] - board[i][mid]);
        }
    }
    vi A, B;
    for(auto& j : v){
        if(query[j].y2 < mid) A.push_back(j);
        if(query[j].y1 > mid) B.push_back(j);
    }
    f(l, mid - 1, A);
    f(mid + 1, r, B);
}

void solve(){
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    cin >> q;
    for(int i{0}; i < q; ++i){
        cin >> query[i].x1 >> query[i].y1 >> query[i].x2 >> query[i].y2;
        query[i].x1--; query[i].y1--; query[i].x2--; query[i].y2--;
        if(query[i].y1 > query[i].y2){
            swap(query[i].x1, query[i].x2);
            swap(query[i].y1, query[i].y2);
        }
    }
    vi p(q);
    iota(p.begin(), p.end(), 0);
    for(int i{0}; i < q; ++i) ans[i] = (ll)1e18;
    f(0, m - 1, p);
    for(int i{0}; i < q; ++i) cout << ans[i] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

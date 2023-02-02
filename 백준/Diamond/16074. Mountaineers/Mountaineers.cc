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

const int sz = 500 * 500;

vi p(sz);

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> board(n, vi(m));
    vp A;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            A.push_back({board[i][j], i * m + j});
        }
    }
    vp Q;
    for(int i{0}; i < q; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        Q.push_back({x1 * m + y1, x2 * m + y2});
    }
    sort(A.begin(), A.end());
    vi l(q), r(q, n * m - 1);
    vi ans(q);
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(1){
        bool ok = false;
        vector<vi> mid(sz);
        for(int i{0}; i < q; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) / 2].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{0}; i < n * m; ++i){
            p[i] = i;
        }
        for(int i{0}; i < n * m; ++i){
            int x = A[i].second / m;
            int y = A[i].second % m;
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] <= board[x][y]) Union(x * m + y, nx * m + ny);
            }
            for(auto& j : mid[i]){
                if(find(Q[j].first) == find(Q[j].second)){
                    r[j] = i - 1;
                    ans[j] = board[x][y];
                }
                else l[j] = i + 1;
            }
        }
    }
    for(int i{0}; i < q; ++i){
        if(Q[i].first == Q[i].second) cout << board[Q[i].first / m][Q[i].second % m] << "\n";
        else cout << ans[i] << "\n";
    }
}

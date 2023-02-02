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

struct edge{
    int x, y, w;
};

const int sz = 500 * 500;
vi p(sz);
vi cnt(sz, 1);

int find(int a){
    if(a == p[a]) return a;
    else return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        cnt[b] += cnt[a];
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<edge> A;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(i + 1 < n) A.push_back({i * m + j, (i + 1) * m + j, abs(board[i][j] - board[i + 1][j])});
            if(j + 1 < m) A.push_back({i * m + j, i * m + j + 1, abs(board[i][j] - board[i][j + 1])});
        }
    }
    sort(A.begin(), A.end(), [&](edge& a, edge& b){
        return a.w < b.w;
    });
    vi start;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            if(a) start.push_back(i * m + j);
        }
    }
    vi l((int)start.size()), r((int)start.size(), (int)A.size() - 1);
    vi rs((int)start.size());
    while(1){
        bool ok = false;
        vector<vi> mid((int)A.size());
        for(int i{0}; i < (int)start.size(); ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{0}; i < n * m; ++i){
            p[i] = i;
            cnt[i] = 1;
        }
        for(int i{0}; i < (int)A.size(); ++i){
            merge(A[i].x, A[i].y);
            for(auto& j : mid[i]){
                int a = find(start[j]);
                if(cnt[a] >= k){
                    rs[j] = A[i].w;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
    }
    ll ans{0};
    for(auto& i : rs) ans += i;
    cout << ans;
}

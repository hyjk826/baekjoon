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

const int sz = 500 * 503;

vi p(sz);

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
    }
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vi cost(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> cost[i];
    }
    vp A;
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            A.push_back({cost[i] * cost[j], i * 501 + j});
        }
    }
    sort(A.begin(), A.end());
    int q;
    cin >> q;
    vp query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].first >> query[i].second;
    }
    vi l(q), r(q, (int)A.size() - 1);
    vi ans(q);
    int aa{0};
    vi ch(sz);
    while(1){
        bool ok = false;
        vector<vi> mid((int)A.size());
        for(int i{0}; i < q; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{1}; i < sz; ++i){
            ch[i] = 0;
            p[i] = i;
        }
        for(int i{0}; i < (int)A.size(); ++i){
            int x = A[i].second / 501;
            int y = A[i].second % 501;
            ch[x * 501 + y] = 1;
            for(auto& j : g[x]){
                if(ch[j * 501 + y]) merge(x * 501 + y, j * 501 + y);
            }
            for(auto& j : g[y]){
                if(ch[x * 501 + j]) merge(x * 501 + y, x * 501 + j);
            }
            for(auto& j : mid[i]){
                int a = find(query[j].first * 501 + query[j].second);
                int b = find(query[j].second * 501 + query[j].first);
                if(a == b){
                    ans[j] = A[i].first;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
    }
    for(auto& i : ans) cout << i << "\n";
}

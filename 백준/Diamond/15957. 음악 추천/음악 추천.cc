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
    int t, p, s;
};

const int sz = 1e5 + 10;
vl tadd(sz), tmul(sz);

void update(int at, ll mul, ll add) {
    for(;at<=sz;at+=at&-at) {
        tmul[at] += mul;
        tadd[at] += add;
    }
}
void range_update(int l, int r, ll by) {
    update(l, by, -by*(l-1));
    update(r+1, -by, by*r);
}

ll query(const int at) {
    if(at==0) return 0;
    ll mul=0, add=0;
    for(int i=at;i;i-=i&-i) {
        mul += tmul[i];
        add += tadd[i];
    }
    return at*mul+add;
}

ll range_sum(ll l, ll r){
    return query(r) - query(l - 1);
}

int main(){
	fastio;
    int n, k, J;
    cin >> n >> k >> J;
    vector<vi> g(n + 1);
    for(int i{2}; i <= n; ++i){
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    int pv{0};
    vi in(n + 1), out(n + 1);
    vi sub(n + 1);
    function<void(int,int)> dfs = [&](int cur, int pre){
        in[cur] = ++pv;
        sub[cur] = 1;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
            sub[cur] += sub[i];
        }
        out[cur] = pv;
    };
    dfs(1, -1);
    vi singer(n + 1);
    vi cnt(n + 1);
    vector<vi> A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> singer[i];
        cnt[singer[i]]++;
        A[singer[i]].push_back(i);
    }
    vector<st> vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i].t >> vec[i].p >> vec[i].s;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.t < y.t;
    });
    vi l(n + 1), r(n + 1, k - 1);
    vi ans(n + 1, -1);
    while(1){
        bool ok = false;
        vector<vi> mid(k);
        for(int i{1}; i <= n; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{0}; i < k; ++i){
            range_update(in[vec[i].p], out[vec[i].p], vec[i].s / sub[vec[i].p]);
            for(auto& j : mid[i]){
                ll sum{0};
                for(auto& a : A[j]){
                    sum += range_sum(in[a], in[a]);
                    if(sum > 1LL * J * cnt[j]) break;
                }
                if(sum > 1LL * J * cnt[j]){
                    ans[j] = vec[i].t;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
        for(int i{1}; i <= n; ++i){
            tadd[i] = tmul[i] = 0;
        }
    }
    for(int i{1}; i <= n; ++i){
        cout << ans[singer[i]] << "\n";
    }
}

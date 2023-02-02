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

struct st2{
    int a, b, c;
};

const int sz = 3e5 + 10;
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
    return query(l) - query(r - 1);
}

int main(){
	fastio; 
    int n, m;   
    cin >> n >> m;
    vector<vi> A(n + 1);
    vi B(m + 1);
    for(int i{1}; i <= m; ++i){
        int a;
        cin >> a;
        A[a].push_back(i);
    }
    for(int i{1}; i <= n; ++i){
        cin >> B[i];
    }
    int k;
    cin >> k;
    vector<st2> C(k + 1);
    for(int i{1}; i <= k; ++i){
        cin >> C[i].a >> C[i].b >> C[i].c;
    }
    vi l(n + 1, 1), r(n + 1, k);
    vi ans(n + 1, -1);
    while(1){
        bool ok = false;
        vector<vi> mid(k + 1);
        for(int i{1}; i <= n; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{1}; i <= k; ++i){
            if(C[i].a <= C[i].b){
                range_update(C[i].a, C[i].b, C[i].c);
            }
            else{
                range_update(C[i].a, m, C[i].c);
                range_update(1, C[i].b, C[i].c);
            }
            for(auto& j : mid[i]){
                ll sum{0};
                for(auto& x : A[j]){
                    sum += range_sum(x, x);
                    if(sum >= B[j]) break;
                }
                if(sum >= B[j]){
                    ans[j] = i;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
        for(int i{1}; i <= m; ++i) {
            tadd[i] = tmul[i] = 0;
        }
    }
    for(int i{1}; i <= n; ++i){
        if(ans[i] == -1) cout << "NIE\n";
        else cout << ans[i] << "\n";
    }
}

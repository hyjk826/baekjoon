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

const int sz = 1e5 + 10;

struct LazyBit{
    vl tadd, tmul;
    LazyBit(){
        tadd.resize(sz);
        tmul.resize(sz);
    }
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
};

int main(){
	fastio;
    LazyBit lb1, lb2;
    int n, k;
    cin >> n >> k;
    vi H(n), A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> H[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    ll ans{LLONG_MAX};
    for(int i{0}; i < n; ++i){
        lb1.range_update(1, H[i] - 1, -B[i]);
        lb1.range_update(H[i], (int)1e5, A[i]);
        lb2.range_update(1, H[i] - 1, B[i] * H[i]);
        lb2.range_update(H[i], (int)1e5, -A[i] * H[i]);
        if(i >= k - 1){
            int l{1}, r{(int)1e5};
            while(r - l >= 3){
                int p = (l * 2 + r) / 3;
                int q = (l + 2 * r) / 3;
                ll x1 = lb1.range_sum(p, p);
                ll y1 = lb2.range_sum(p ,p);
                ll x2 = lb1.range_sum(q, q);
                ll y2 = lb2.range_sum(q, q);
                if(x1 * p + y1 > x2 * q + y2) l = p;
                else r = q;
            }
            for(int i{l}; i <= r; ++i){
                ll x = lb1.range_sum(i, i);
                ll y = lb2.range_sum(i, i);
                ans = min(ans, x * i + y);
            }
            lb1.range_update(1, H[i - k + 1] - 1, B[i - k + 1]);
            lb1.range_update(H[i - k + 1], (int)1e5, -A[i - k + 1]);
            lb2.range_update(1, H[i - k + 1] - 1, -B[i - k + 1] * H[i - k + 1]);
            lb2.range_update(H[i - k + 1], (int)1e5, A[i - k + 1] * H[i - k + 1]);
        }
    }
    cout << ans;
}

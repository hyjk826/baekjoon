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

string s;
int n;

const ll p1 = 179, mod1 = 1e9 - 63;
const ll p2 = 917, mod2 = 1e9 + 7;

const int sz = 1e6 + 10;
ll pw1[sz], pw2[sz], pre1[sz], pre2[sz];

ll oneHashing(string& str){
    ll r1{0}, r2{0};
    int n = (int)str.size();
    for(int i{n - 1}; i >= 0; --i) r1 = (r1 * p1 + str[i] - 'A') % mod1;
    for(int i{n - 1}; i >= 0; --i) r2 = (r2 * p2 + str[i] - 'A') % mod2;
    return (r1 << 32 | r2);
}

struct st {
	ll v1, v2, lazy;
    st() : v1(0), v2(0), lazy(-1){}
};

vector<st> seg(sz * 4);
vector<ll> vec(sz);


void init(int node, int l, int r) {
	if (l == r) {
        seg[node].v1 = vec[l];
        seg[node].v2 = vec[l];
        return;
    }
	int m{ (l + r) >> 1 };
    init(node << 1, l, m);
    init(node << 1 | 1, m + 1, r);
    auto a = seg[node << 1];
    auto b = seg[node << 1 | 1];
    seg[node].v1 = a.v1 + b.v1 * pw1[m + 1 - l];
    seg[node].v2 = a.v2 + b.v2 * pw2[m + 1 - l];
    seg[node].v1 %= mod1;
    seg[node].v2 %= mod2;
}

void propagate(int node, int l, int r){
	if (seg[node].lazy != -1) {
		seg[node].v1 = seg[node].lazy * pre1[r - l] % mod1;
        seg[node].v2 = seg[node].lazy * pre2[r - l] % mod2;
        seg[node].v1 %= mod1;
        seg[node].v2 %= mod2;
		if (l != r) {
			seg[node << 1].lazy = seg[node].lazy;
			seg[node << 1 | 1].lazy = seg[node].lazy;
		}
		seg[node].lazy = -1;
	}
}

void update(int node, int l, int r, int s, int e, ll diff) {
	propagate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy = diff;
		propagate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	update(node << 1, l, m, s, e, diff);
	update(node << 1 | 1, m + 1, r, s, e, diff);
	auto a = seg[node << 1];
    auto b = seg[node << 1 | 1];
    seg[node].v1 = a.v1 + b.v1 * pw1[m + 1 - l];
    seg[node].v2 = a.v2 + b.v2 * pw2[m + 1 - l];
    seg[node].v1 %= mod1;
    seg[node].v2 %= mod2;
}

pl query(int node, int l, int r, int s, int e){
	propagate(node, l, r);
	if (e < l || r < s) return {0, 0};
	if (s <= l && r <= e){
        return {seg[node].v1 * pw1[l - s] % mod1, seg[node].v2 * pw2[l - s] % mod2};
    }
	int m{ (l + r) >> 1};
	auto a = query(node << 1, l, m, s, e);
    auto b = query(node << 1 | 1, m + 1, r, s, e);
    return {(a.first + b.first) % mod1, (a.second + b.second) % mod2};
}


int main(){
	fastio;
    cin >> s >> n;
    unordered_set<ll> stt;
    for(int i{0}; i < n; ++i){
        string a;
        cin >> a;
        stt.insert(oneHashing(a));
    }
    pw1[0] = pw2[0] = pre1[0] = pre2[0] = 1;
    for(int i{1}; i <= s.size(); ++i){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
        pre1[i] = pw1[i] + pre1[i - 1];
        pre1[i] %= mod1;
        pre2[i] = pw2[i] + pre2[i - 1];
        pre2[i] %= mod2;
    }
    for(int i{1}; i <= (int)s.size(); ++i){
        vec[i] = s[i - 1]- 'A';
    }
    int szz = (int)s.size();
    init(1, 1, szz);
    int q;
    cin >> q;
    while(q--){
        int op, l, r; char cc;
        cin >> op;
        if(op == 1){
            cin >> l >> r >> cc;
            update(1, 1, szz, l, r, cc - 'A');
        }
        else{
            cin >> l >> r;
            auto ret = query(1, 1, szz, l, r);
            if(stt.count(ret.first << 32 | ret.second)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}

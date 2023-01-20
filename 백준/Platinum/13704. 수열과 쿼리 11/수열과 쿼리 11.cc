// 2022-01-20
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
    int l, r, idx;
};

int n, q, l, r, k;
vector<st> query(100001);
vi vec(100001);
vl cnt(1 << 21);
ll sum{0};

void push_l(int idx){
    cnt[vec[idx]]++;
    sum += cnt[k ^ vec[idx - 1]];
}

void push_r(int idx){
    sum += cnt[k ^ vec[idx]];
    if(vec[l - 1] == (k ^ vec[idx])) sum++;
    cnt[vec[idx]]++;
}

void erase_l(int idx){
    sum -= cnt[k ^ vec[idx - 1]];
    cnt[vec[idx]]--;
}

void erase_r(int idx){
    sum -= cnt[k ^ vec[idx]];
    if(vec[l - 1] == (k ^ vec[idx])) sum--;
    cnt[vec[idx]]--;
}

int main() {
	fastio;	
    cin >> n >> k;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] ^= vec[i - 1];
    }
    cin >> q;
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }

    int sq = sqrt(n);
    sort(query.begin(), query.begin() + q, [&](st& a, st& b){
        if(a.l / sq == b.l / sq) return a.r < b.r;
        else return a.l / sq < b.l / sq;
    });

    l = query[0].l;
    r = query[0].r;
    vl ans(q);
    for(int i{l}; i <= r; ++i){
        push_r(i);
    }
    ans[query[0].idx] = sum;

    for(int i{1}; i < q; ++i){
        while(l < query[i].l) erase_l(l++);
        while(l > query[i].l) push_l(--l);
        while(r < query[i].r) push_r(++r);
        while(r > query[i].r) erase_r(r--);
        ans[query[i].idx] = sum;
    }

    for(auto& i : ans) cout << i << "\n";
}
	

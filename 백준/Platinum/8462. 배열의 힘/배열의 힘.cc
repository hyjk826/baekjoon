// 2022-11-25
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

vi cnt((int)1e6 + 1);
vi vec((int)1e5 + 1);
ll sum{0};

void p(int idx){
    sum -= 1LL * cnt[vec[idx]] * cnt[vec[idx]] * vec[idx];
    cnt[vec[idx]]++;
    sum += 1LL * cnt[vec[idx]] * cnt[vec[idx]] * vec[idx];
}

void m(int idx){
    sum -= 1LL * cnt[vec[idx]] * cnt[vec[idx]] * vec[idx];
    cnt[vec[idx]]--;
    sum += 1LL * cnt[vec[idx]] * cnt[vec[idx]] * vec[idx];
}

int main() {
	fastio;	
    int n, q;
    cin >> n >> q;    
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vector<st> query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }
    int sq = sqrt(n);
    sort(query.begin(), query.end(), [&](st& a, st& b){
        if(a.l / sq == b.l / sq) return a.r < b.r;
        else return a.l / sq < b.l / sq;
    });    
    int l = query[0].l;
    int r = query[0].r;
    for(int i{l}; i <= r; ++i){
        p(i);
    }
    vl ans(q);
    ans[query[0].idx] = sum;
    for(int i{1}; i < q; ++i){
        while(l < query[i].l) m(l++);
        while(l > query[i].l) p(--l);
        while(r < query[i].r) p(++r);
        while(r > query[i].r) m(r--);
        ans[query[i].idx] = sum;
    }
    for(auto& i : ans){
        cout << i << "\n";
    }
}
	

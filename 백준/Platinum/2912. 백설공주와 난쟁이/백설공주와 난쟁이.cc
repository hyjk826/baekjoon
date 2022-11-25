// 2022-11-24
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

int n, q;
vi vec(300001);
vi cnt(10001);
vi same(300001);
int sum{0};
vector<st> query(10001);
int l, r, c;

void Plus(int k){
    cnt[k]++;
}

void Minus(int k){
    cnt[k]--;
}

int check(){
    for(int i{1}; i <= c; ++i){
        if(cnt[i] > (r - l + 1) / 2){
            return i;
        }
    }
    return -1;
}

int main() {
	fastio;	
    cin >> n >> c;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
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
    vi ans(q);
    for(int i{l}; i <= r; ++i){
        Plus(vec[i]);
    }
    ans[query[0].idx] = check();
    for(int i{1}; i < q; ++i){
        while(l < query[i].l) Minus(vec[l++]);
        while(l > query[i].l) Plus(vec[--l]);
        while(r < query[i].r) Plus(vec[++r]);
        while(r > query[i].r) Minus(vec[r--]);
        ans[query[i].idx] = check();
    }
    for(auto& i : ans){
        if(i == -1) cout << "no\n";
        else{
            cout << "yes ";
            cout << i << "\n";
        }
    }
}
	

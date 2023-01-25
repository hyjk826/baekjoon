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

int n, q, sq;
int bucket[320][100001];
vi cnt(100001);
int sum{0};
vector<st> query(100001);
vi bmx(320);

void Plus(int k){
    int num = k / sq;
    if(cnt[k] == bmx[num]) bmx[num]++;
    bucket[num][cnt[k]]--;
    cnt[k]++;
    bucket[num][cnt[k]]++;
}

void Minus(int k){
    int num = k / sq;
    bucket[num][cnt[k]]--;
    cnt[k]--;
    bucket[num][cnt[k]]++;
    if(bucket[num][bmx[num]] == 0) bmx[num]--;
}

int f(){
    int mx{0};
    for(int i{319}; i >= 0; --i){
        mx = max(mx, bmx[i]);
    }
    for(int i{n / sq}; i >= 0; --i){
        if(bmx[i] != mx) continue;
        for(int j{sq - 1}; j >= 0; --j){            
            if(cnt[i * sq + j] == mx){
                return i * sq + j;
            }
        }
    }
    return 0;
}

int main() {
	fastio;	
    cin >> n >> q;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vi A = vec;
    sort(A.begin(), A.end());
    for(int i{1}; i <= n; ++i){
        vec[i] = lower_bound(A.begin(), A.end(), vec[i]) - A.begin();
    }
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }
    sq = sqrt(n);
    sort(query.begin(), query.begin() + q, [&](st& a, st& b){
        if(a.l / sq == b.l / sq) return a.r < b.r;
        else return a.l / sq < b.l / sq;
    });
    int l = query[0].l;
    int r = query[0].r;
    vi ans(q);
    for(int i{l}; i <= r; ++i){
        Plus(vec[i]);
    }
    ans[query[0].idx] = A[f()];
    for(int i{1}; i < q; ++i){
        while(l > query[i].l) Plus(vec[--l]);
        while(r < query[i].r) Plus(vec[++r]);
        while(l < query[i].l) Minus(vec[l++]);
        while(r > query[i].r) Minus(vec[r--]);
        ans[query[i].idx] = A[f()];
    }
    for(auto& i : ans) cout << i << "\n";
}
	

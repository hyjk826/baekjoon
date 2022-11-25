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

#define MX 200001
int n, q;
int vec[MX];
int cnt[MX];
int same[MX];
int sum{0};

void Plus(int k){
    if(cnt[k]) same[cnt[k]]--;
    cnt[k]++;
    same[cnt[k]]++;
    sum = max(sum, cnt[k]);
}

void Minus(int k){
    same[cnt[k]]--;
    if(cnt[k] == sum && same[cnt[k]] == 0) sum--;
    cnt[k]--;
    same[cnt[k]]++;
}


int main() {
	fastio;	
    while(1){
        cin >> n;
        if(n == 0) return 0;
        cin >> q;
        memset(cnt, 0, sizeof(cnt));
        memset(same, 0, sizeof(same));
        memset(vec, 0, sizeof(vec));
        sum = 0;
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
            vec[i] += (int)1e5;
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
        vi ans(q);
        for(int i{l}; i <= r; ++i){
            Plus(vec[i]);
        }
        ans[query[0].idx] = sum;
        for(int i{1}; i < q; ++i){
            while(l < query[i].l) Minus(vec[l++]);
            while(l > query[i].l) Plus(vec[--l]);
            while(r < query[i].r) Plus(vec[++r]);
            while(r > query[i].r) Minus(vec[r--]);
            ans[query[i].idx] = sum;
        }
        for(auto& i : ans) cout << i << "\n";
    }
}
	

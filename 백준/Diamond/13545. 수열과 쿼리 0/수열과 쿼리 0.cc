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

const int sz = 2e5 + 10000;
int n, k, q, sq;
vector<st> query(sz);
vector<list<int> > dQ(sz);
vi cnt(sz);
vi vec(sz);
vi bucket(sz);

void insert_l(int idx){
    int value = vec[idx];
    if(!dQ[value].empty()){
        int a = dQ[value].back() - dQ[value].front();
        cnt[a]--;
        bucket[a / sq]--;
    }
    dQ[value].push_front(idx);
    int a = dQ[value].back() - dQ[value].front();
    cnt[a]++;
    bucket[a / sq]++;
}

void insert_r(int idx){
    int value = vec[idx];
    if(!dQ[value].empty()){
        int a = dQ[value].back() - dQ[value].front();
        cnt[a]--;
        bucket[a / sq]--;
    }
    dQ[value].push_back(idx);
    int a = dQ[value].back() - dQ[value].front();
    cnt[a]++;
    bucket[a / sq]++;
}

void erase_l(int idx){
    int value = vec[idx];
    int a = dQ[value].back() - dQ[value].front();
    cnt[a]--;
    bucket[a / sq]--;
    dQ[value].pop_front();
    if(!dQ[value].empty()){
        int a = dQ[value].back() - dQ[value].front();
        cnt[a]++;
        bucket[a / sq]++;
    }
}

void erase_r(int idx){
    int value = vec[idx];
    int a = dQ[value].back() - dQ[value].front();
    cnt[a]--;
    bucket[a / sq]--;
    dQ[value].pop_back();
    if(!dQ[value].empty()){
        int a = dQ[value].back() - dQ[value].front();
        cnt[a]++;
        bucket[a / sq]++;
    }
}

int f(){
    for(int i{n / sq}; i >= 0; --i){
        if(bucket[i] == 0) continue;
        for(int j{sq - 1}; j >= 0; --j){
            if(cnt[i * sq + j]) return i * sq + j;
        }
    }
    return 0;
}

int main() {
	fastio;	
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    for(int i{0}; i <= n; ++i){
        vec[i] += 1e5;
    }
    cin >> q;
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r;
        query[i].l--;
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
        insert_r(i);
    }
    ans[query[0].idx] = f();
    for(int i{1}; i < q; ++i){
        while(l > query[i].l) insert_l(--l);
        while(r < query[i].r) insert_r(++r);
        while(l < query[i].l) erase_l(l++);
        while(r > query[i].r) erase_r(r--);
        ans[query[i].idx] = f();
    }
    for(auto& i : ans) cout << i << "\n";
}
	

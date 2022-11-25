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

template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T f(int a, int b){
    if(a == 0) return sum(b + 1);
    else return sum(b + 1) - sum(a);
  }
};

struct st{
    int l, r, idx;
};

int n, q, k;
vi vec(100001);
ll sum{0};
vector<st> query(100001);
binary_indexed_tree<int> BIT(100001);


void Plus(int a){
    sum += BIT.f(max(a - k, 1), min(100000, a + k));
    BIT.add(a, 1);
}

void Minus(int a){
    sum -= BIT.f(max(a - k, 1), min(100000, a + k)) - 1;
    BIT.add(a, -1);
}


int main() {
	fastio;	
    cin >> n >> k;
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
    int l = query[0].l;
    int r = query[0].r;
    vl ans(q);
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
	

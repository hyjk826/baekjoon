// 2022-10-04
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
    int l, r, num;
};


int main() {
	fastio;
    int n, q;
    cin >> n;
    vi c(n);
    for(int i{0}; i < n; ++i){
        cin >> c[i];
    }
    vi A = c;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{0}; i < n; ++i){
        c[i] = lower_bound(A.begin(), A.end(), c[i]) - A.begin();
    }
    cin >> q;
    vector<st> query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r;
        query[i].l--;
        query[i].r--;
        query[i].num = i;
    }
    sort(query.begin(), query.end(), [&](st a, st b){
        if(a.r == b.r) return a.l < b.l;
        else return a.r < b.r;
    });
    vi last(n, -1);
    binary_indexed_tree<int> BIT(n + 1);
    vi ans(q);
    int k{0};
    for(int i{0}; i < q; ++i){
        while(k <= query[i].r){
            if(last[c[k]] != -1){
                BIT.add(last[c[k]], -1);
            }
            last[c[k]] = k;
            BIT.add(k, 1);
            k++;
        }
        ans[query[i].num] = BIT.f(query[i].l, query[i].r);
    }
    for(auto& i : ans) cout << i << "\n";
}
	


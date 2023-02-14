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
    int l, r, c;
};

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


int main(){
	fastio;
    int n;
    cin >> n;
    vector<st> vec(n);
    vi A;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].l >> vec[i].r >> vec[i].c;
        A.push_back(vec[i].l);
        A.push_back(vec[i].r);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{0}; i < n; ++i){
        vec[i].l = lower_bound(A.begin(), A.end(), vec[i].l) - A.begin();
        vec[i].r = lower_bound(A.begin(), A.end(), vec[i].r) - A.begin();
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        if(x.l == y.l) return x.r < y.r;
        else return x.l > y.l;
    });
    binary_indexed_tree<ll> BIT((int)2e6 + 10);
    ll ans{0};
    for(int i{0}; i < n; ++i){
        BIT.add(vec[i].r, vec[i].c);
        ans = max(ans, BIT.f(0, vec[i].r));
    }
    cout << ans;
}

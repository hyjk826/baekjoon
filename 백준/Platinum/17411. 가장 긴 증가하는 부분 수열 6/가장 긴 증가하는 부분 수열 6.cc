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

vi LIS(vi& vec){
    int n = (int)vec.size();
    vi v;
    v.push_back(-MAX);
    vi cnt(n);
    for(int i{0}; i < n; ++i){
        if(v.back() < vec[i]){
            v.push_back(vec[i]);
            cnt[i] = v.size() - 1;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), vec[i]);
            cnt[i] = it - v.begin();
            *it = vec[i];
        }
    }
    return cnt;
}

template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N = 1): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      BIT[i] %= MOD;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      ans %= MOD;
      i -= i & -i;
    }
    return ans;
  }
  T f(int a, int b){
    if(a == 0) return sum(b + 1);
    else return (sum(b + 1) - sum(a) + MOD) % MOD;
  }
};


void solve(){
	int n;
    cin >> n;
    vi vec(n);
    for(auto& i : vec) cin >> i;
    auto cnt = LIS(vec);
    int mx = *max_element(cnt.begin(), cnt.end());
    vector<vi> g(mx + 1);
    for(int i{0}; i < n; ++i){
      g[cnt[i]].push_back(vec[i]);
    }
    for(int i{1}; i <= mx; ++i) {
      sort(g[i].begin(), g[i].end());
      g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    vector<binary_indexed_tree<int> > BIT(mx + 1);
    for(int i{1}; i <= mx; ++i){
      BIT[i].N = g[i].size();
      BIT[i].BIT.resize(BIT[i].N + 1);
    }
    vl ans(n);
    for(int i{0}; i < n; ++i){
      int idx = lower_bound(g[cnt[i]].begin(), g[cnt[i]].end(), vec[i]) - g[cnt[i]].begin();
      if(cnt[i] == 1) {
        BIT[cnt[i]].add(idx, 1);
        ans[i] = 1;
      }
      else{
        int idx2 = lower_bound(g[cnt[i] - 1].begin(), g[cnt[i] - 1].end(), vec[i]) - g[cnt[i] - 1].begin();
        ans[i] = BIT[cnt[i] - 1].sum(idx2);
        BIT[cnt[i]].add(idx, ans[i]);
      }
    }
    ll res{0};
    for(int i{0}; i < n; ++i){
      if(cnt[i] == mx) {
        res += ans[i];
        res %= MOD;
      }
    }
    cout << mx << " " << res << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

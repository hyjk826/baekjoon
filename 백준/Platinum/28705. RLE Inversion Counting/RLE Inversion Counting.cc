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
      ans %= MOD;
      i -= i & -i;
    }
    return ans;
  }
  T f(int a, int b){
    if(a > b) return 0LL;
    if(a == 0) return sum(b + 1);
    else return (sum(b + 1) - sum(a) + MOD) % MOD;
  }
};


void solve(){
	int m;
    cin >> m;
    vi re;
    vi A;
    vector<vi> vec;
    for(int i{0}; i < m; ++i){
        int k, n;
        cin >> k >> n;
        re.push_back(k);
        vi tmp(n);
        for(auto& j : tmp){
            cin >> j;
            A.push_back(j);
        }
        vec.push_back(tmp);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    binary_indexed_tree<ll> BIT((int)A.size() + 10);
    ll ans{0};
    for(int i{0}; i < m; ++i){
        auto tmp = vec[i];
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        binary_indexed_tree<int> BIT2((int)tmp.size() + 1);
        for(auto j : vec[i]){
            int q = j;
            q = lower_bound(tmp.begin(), tmp.end(), j) - tmp.begin();            
            ans += 1LL * re[i] * BIT2.f(q + 1, (int)tmp.size() - 1);
            BIT2.add(q ,1);
            ans %= MOD;
            q = lower_bound(A.begin(), A.end(), j) - A.begin();
            ans += 1LL * re[i] * BIT.f(q + 1, (int)A.size() - 1) % MOD;
            ans %= MOD;
        }
        for(auto j : vec[i]){
            j = lower_bound(tmp.begin(), tmp.end(), j) - tmp.begin();
            ans += 1LL * (1LL * (re[i] - 1) * re[i] / 2 % MOD) * BIT2.f(j + 1, (int)tmp.size() - 1);
            ans %= MOD;
        }
        for(auto j : vec[i]){
            j = lower_bound(A.begin(), A.end(), j) - A.begin();
            BIT.add(j, re[i]);
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

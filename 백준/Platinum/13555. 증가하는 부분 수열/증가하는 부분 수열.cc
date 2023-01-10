// 2023-01-09
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
#define MOD 5000000
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

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vector<binary_indexed_tree<ll>> BIT(k + 1, (100001));
    BIT[0].add(0, 1);
    for(int i{0}; i < n; ++i){
        for(int j{1}; j <= k; ++j){
            ll k = BIT[j - 1].f(0, vec[i] - 1);
            BIT[j].add(vec[i], k);
        }
    }
    cout << BIT[k].f(0, 100000);
}

// 2022-07-17
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    map<int, int> m;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        m[a] = i;
    }
    ll ans{0};
    binary_indexed_tree<int> BIT(n + 1);
    for(int i{0}; i < n; ++i){
        ans += BIT.f(m[A[i]] + 1, n - 1);
        BIT.add(m[A[i]], 1);
    }
    cout << ans;
}

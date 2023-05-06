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


int main(){
	fastio;
	int n;
    cin >> n;
    vi A(n), B(n);
    vi C(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
        C[B[i]] = i;
    }
    vi l(n), r(n);
    binary_indexed_tree<int> BIT(n + 1);
    BIT.add(C[A[0]], 1);
    for(int i{1}; i < n; ++i){
        int idx = C[A[i]];
        l[i] = BIT.f(0, idx - 1);
        BIT.add(idx, 1);
    }
    binary_indexed_tree<int> BIT2(n + 1);
    BIT2.add(C[A[n - 1]], 1);
    for(int i{n - 2}; i >= 0; --i){
        int idx = C[A[i]];
        r[i] = BIT2.f(idx + 1, n - 1);
        BIT2.add(idx, 1);
    }
    ll ans{0};
    for(int i{1}; i < n - 1; ++i){
        ans += 1LL * l[i] * r[i];
    }
    if(ans == 0) cout << "Attention is what I want";
    else{
        cout << "My heart has gone to paradise\n" << ans;
    }
}

// 2022-12-23
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
	int n;
    cin >> n;
    binary_indexed_tree<int> BIT(n + 1);
    vi vec(n);
    vi where(n + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        where[vec[i]] = i;
    }
    for(int i{1}; i <= n / 2; ++i){
        int idx = where[i];
        if(idx >= 1){
            cout << idx - BIT.f(0, idx - 1) << "\n";
        }
        else cout << 0 << "\n";
        BIT.add(idx, 1);
        idx = where[n + 1 - i];
        if(idx + 1 <= n){
            cout << n - (idx + 1) - BIT.f(idx + 1, n - 1) << "\n";
        }
        else cout << 0 << "\n";
        BIT.add(idx, 1);
    }
    if(n & 1){
        int idx = where[n / 2 + 1];
        if(idx >= 1){
            cout << idx - BIT.f(0, idx - 1) << "\n";
        }
        else cout << 0 << "\n";
    }
}

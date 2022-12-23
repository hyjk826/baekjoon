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
    fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    binary_indexed_tree<int> BIT(n + 1);
    vi ans(n);
    for(int i{0}; i < n; ++i){
        int l{0}, r{n - 1};
        int k;
        while(l <= r){
            int mid{(l + r) / 2};
            if(mid + 1 - BIT.f(0, mid) < vec[i] + 1){
                l = mid + 1;
            }
            else{
                r = mid - 1;
                k = mid;
            }
        }
        ans[k] = i + 1;
        BIT.add(k, 1);
    }
    for(auto& i : ans) cout << i << "\n";
}

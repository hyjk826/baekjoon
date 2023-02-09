// 2022-04-01
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
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
};

int main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vl vec(n);
    binary_indexed_tree<ll> bit(n + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        bit.add(i, vec[i]);
    }
    for(int i{0}; i < m + k; ++i){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            ll c;
            cin >> b >> c;
            b--;
            ll dif = c - vec[b];
            vec[b] = c;
            bit.add(b, dif);
        }
        else{
            int b, c;
            cin >> b >> c;
            b--;
            c--;
            cout << bit.sum(c + 1) - bit.sum(b) << '\n';
        }
    }
}
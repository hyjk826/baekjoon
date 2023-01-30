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
    vi pos(n + 1, -1);
    binary_indexed_tree<int> BIT(2 * n + 1);
    ll ans{0};
    for(int i{0}; i < 2 * n; ++i){
        int a;
        cin >> a;
        if(pos[a] == -1) {
            BIT.add(i, 1);
            pos[a] = i;
        }
        else{
            BIT.add(pos[a], -1);
            ans += BIT.f(pos[a], i - 1);
            pos[a] = -1;
        }
    }
    cout << ans;
}

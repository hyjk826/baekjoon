// 2022-12-26
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
    int n, r;
    cin >> n >> r;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi in(n), out(n);
    int cnt{-1};
    vi depth(n + 1);
    depth[r] = 1;
    function<void(int, int)> dfs = [&](int cur, int pre){
        in[cur] = ++cnt;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            depth[i] = depth[cur] + 1;
            dfs(i, cur);
        }
        out[cur] = cnt;
    };
    dfs(r, -1);
    binary_indexed_tree<int> BIT(n + 1);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            BIT.add(in[b], 1);
        }
        else{
            cout << 1LL * depth[b] * BIT.f(in[b], out[b]) << "\n";
        }
    }
}

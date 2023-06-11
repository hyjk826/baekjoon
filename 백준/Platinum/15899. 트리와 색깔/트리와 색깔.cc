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


void solve(){
    int n, q, c;
    cin >> n >> q >> c;
    vector<vi> color(c);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        a--;
        color[a].push_back(i);
    }
    vector<vi> g(n);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi in(n), out(n);
    int pv{0};
    function<void(int,int)> dfs = [&](int cur, int pre){
        in[cur] = ++pv;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
        }
        out[cur] = pv;
    };
    dfs(0, -1);
    vector<vi> query(c + 1);
    for(int i{0}; i < q; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        query[b].push_back(a);
    }
    ll ans{0};
    binary_indexed_tree<int> BIT(n + 10);
    for(int i{0}; i < c; ++i){
        for(auto& j : color[i]){
            BIT.add(in[j], 1);
        }
        for(auto& j : query[i]){
            ans += BIT.f(in[j], out[j]);
            ans %= MOD;
        }
    }
    cout << ans;
}

int main(){
	fastio;
	int T;
    T = 1;
	while(T--){
		solve();
	}
}

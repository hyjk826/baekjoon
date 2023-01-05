// 2023-01-05
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

int n, q;
const int sz = (int)2e5 + 1;
vector<vi> g(sz);
vi sub(sz), depth(sz, -1), par(sz), top(sz), in(sz);

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

void dfs1(int cur = 1){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        depth[i] = depth[cur] + 1;
        par[i] = cur;
        dfs1(i);
        sub[cur] += sub[i];
        if(sub[i] > sub[g[cur][0]]) swap(i, g[cur][0]);
    }
}

int pv{0};

void dfs2(int cur = 1){
    in[cur] = ++pv;
    for(auto& i : g[cur]){
        if(i == g[cur][0]){
            top[i] = top[cur];
        }
        else top[i] = i;
        dfs2(i);
    }
}

binary_indexed_tree<int> BIT(sz + 1);

void update(int a){
    BIT.add(in[a], 1);
}

int query(int a, int b){
    int ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret += BIT.f(in[st], in[a]);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret += BIT.f(in[a] + 1, in[b]);
    return ret;
}


int main(){
	fastio;
    cin >> n >> q;
    for(int i{2}; i <= n; ++i){
        int a;
        cin >> a;
        g[a].push_back(i);
    }
    dfs1();
    dfs2();
    while(q--){
        int b, c, d;
        cin >> b >> c >> d;
        if(d == 0){
            if(query(b, c)) cout << "NO\n";
            else cout << "YES\n";
        }
        else{
            if(query(b, c)){
                cout << "NO\n";
                update(c);
            }
            else{
                cout << "YES\n";
                update(b);
            }
        }
    }
}

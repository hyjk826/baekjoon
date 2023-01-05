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
const int sz = (int)1e5 + 1;
vector<vi> g(sz), tempg(sz);
vi sub(sz), depth(sz), par(sz), top(sz), in(sz), A(sz);


template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, int x){
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

void dfs0(int cur = 1, int pre = -1){
    for(auto& i : tempg[cur]){
        if(i == pre) continue;
        g[cur].push_back(i);
        dfs0(i, cur);
    }
}

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
    A[pv] = cur;
    for(auto& i : g[cur]){
        if(i == g[cur][0]){
            top[i] = top[cur];
        }
        else top[i] = i;
        dfs2(i);
    }
}

binary_indexed_tree<int> BIT(sz);

void update(int a){
    if(BIT.f(in[a], in[a]) == 0) BIT.add(in[a], 1);
    else BIT.add(in[a], -1);
}

int query(int a, int b){
    function<int(int,int)> f = [&](int x, int y){
        int k = BIT.f(x, y);
        if(k == 0) return -1;
        int l = x;
        int r = y;
        int ret{-1};
        while(l <= r){
            int mid{(l + r) / 2};
            if(BIT.f(l, mid)){
                r = mid - 1;
                ret = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ret;
    };
    int ret = -1;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        int k = f(in[st], in[a]);
        if(k != -1) ret = k;
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    int k = f(in[a], in[b]);
    if(k != -1) ret = k;
    if(ret == -1) return ret;
    return A[ret];
}

int main(){
	fastio;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    dfs0();
    dfs1();
    dfs2();
    cin >> q;
    while(q--){
        int op, a;
        cin >> op >> a;
        if(op == 1){
            update(a);
        }
        else{
            cout << query(1, a) << "\n";
        }
    }
}

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

struct st {
	ll v, lazy;
};

vector<st> segTree(400001);
vector<ll> vec(100001);



void update(int node, int l, int r, int s, int e, ll diff) {
	if (segTree[node].lazy != 0) {
		segTree[node].v += segTree[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		segTree[node].v += diff * (ll)(r-l+1);
		if (l != r) {
			segTree[node * 2].lazy += diff;
			segTree[node * 2 + 1].lazy += diff;
		}
		return;
	}
	int m{ (l + r) / 2 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	segTree[node].v = segTree[node * 2].v + segTree[node * 2 + 1].v;
}

ll sum(int node, int l, int r, int s, int e) {
	if (segTree[node].lazy != 0) {
		segTree[node].v += segTree[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return segTree[node].v;
	int m{ (l + r) / 2 };
	return sum(node * 2, l, m, s, e) + sum(node * 2 + 1, m + 1, r, s, e);
}

int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    vector<vi> g(n + 1);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(i == 0) continue;
        g[a].push_back(i + 1);
    }
    vi in(n + 1), out(n + 1);
    int cnt{-1};
    function<void(int, int)> dfs = [&](int cur, int pre){
        in[cur] = ++cnt;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
        }
        out[cur] = cnt;
    };
    dfs(1, -1);
    binary_indexed_tree<ll> BIT(n + 1);
    bool flag = true;
    while(q--){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            if(flag){
                update(1, 0, n - 1, in[a], out[a], b);
            }
            else{
                BIT.add(in[a], b);
            }
        }
        else if(op == 2){
            int a;
            cin >> a;
            cout << sum(1, 0, n - 1, in[a], in[a]) + BIT.f(in[a], out[a]) << "\n";
        }
        else if(op == 3){
            flag ^= 1;
        }
    }
}

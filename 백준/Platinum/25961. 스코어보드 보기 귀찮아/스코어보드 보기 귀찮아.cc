// 2022-12-02
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

int main() {
	fastio;
	int n, s, q;
    cin >> n >> s >> q;
    binary_indexed_tree<int> BIT(q + 1);
    int rank{n};
    vi cnt(n + 1);
    vi last(n + 1);
    BIT.add(0, n);
    for(int i{0}; i < q; ++i){
        int a;
        cin >> a;
        if(a == 1){
            int k = BIT.f(cnt[a] + 1, q);
            rank = k + 1;
        }
        else{
            if(cnt[a] == cnt[1] && last[a] > last[1]){
                rank++;
            }
        }
        BIT.add(cnt[a], -1);
        BIT.add(cnt[a] + 1, 1);
        cnt[a]++;
        last[a] = i;
        cout << rank << " ";
        int l{0}, r{q};
        int ans{0};
        while(l <= r){
            int m{(l + r) / 2};
            int b = BIT.f(m, q);
            if(b >= s){
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        if(rank > s){
            cout << ans - cnt[1] + 1 << "\n";
        }
        else cout << 0 << "\n";
    }
}
	

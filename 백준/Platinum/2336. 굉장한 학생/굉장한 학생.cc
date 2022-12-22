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
  binary_indexed_tree(int N): N(N), BIT(N + 1, MAX){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] = min(BIT[i], x);
      i += i & -i;
    }
  }
  T query(int i){
    T ans = MAX;
    while (i > 0){
      ans = min(ans, BIT[i]);
      i -= i & -i;
    }
    return ans;
  }
};

struct st{
    int a, b, c;
    bool operator< (const st& x) const{
        return a < x.a;
    }
};

int main(){
    int n;
    cin >> n;
    vector<st> vec(n + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        vec[a].a = i;
    }
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        vec[a].b = i;
    }
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        vec[a].c = i;
    }
    sort(vec.begin() + 1, vec.end());
    binary_indexed_tree<int> BIT(n + 10);
    int ans{0};
    for(int i{1}; i <= n; ++i){
        if(BIT.query(vec[i].b + 1) > vec[i].c) ans++;
        BIT.add(vec[i].b, vec[i].c);
    }
    cout << ans;
}

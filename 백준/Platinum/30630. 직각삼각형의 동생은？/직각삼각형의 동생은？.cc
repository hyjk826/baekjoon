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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct st{
    int x, y, k;
};

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
	int n;
    cin >> n;
    vector<st> vec(n);
    vi A, B;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y;
        vec[i].k = -1;
        A.push_back(vec[i].x); 
    }
    int q;
    cin >> q;
    vi ans(q);
    for(int i{0}; i < q; ++i){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b, i});
        A.push_back(a); 
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        ll a1 = 1LL * a.x * a.x + 1LL * a.y * a.y;
        ll b1 = 1LL * b.x * b.x + 1LL * b.y * b.y;
        if(1LL * a.y * b.x == 1LL * a.x * b.y){
            if(a1 == b1) return a.k < b.k;
            return a1 < b1;
        }
        else return 1LL * a.y * b.x < 1LL * a.x * b.y;
    });
    sort(A.begin(), A.end()); A.erase(unique(A.begin(), A.end()), A.end());
    binary_indexed_tree<int> BIT((int)A.size() + 10);
    for(int i{0}; i < n + q; ++i){
        int x = lower_bound(A.begin(), A.end(), vec[i].x)- A.begin();
        if(vec[i].k == -1) BIT.add(x, 1);
        else{
            ans[vec[i].k] = BIT.f(0, x);
        }
    }
    for(auto& i : ans) cout << i << "\n";
    
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

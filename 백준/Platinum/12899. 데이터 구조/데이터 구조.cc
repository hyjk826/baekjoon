// 2022-07-18
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

// index 0 부터 시작 add(0 ~ n - 1, dif(b -> c (c - b))) 
// vec[0] + vec[1] + ... vec[k] -> sum(k + 1)   vec[b] ~ vec[c] 의 합 -> sum(c + 1) - sum(b)
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
	int n;
    cin >> n;
    binary_indexed_tree<int> BIT(2000001);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            BIT.add(b, 1);
        }
        else{
            int l{1}, r{2000000};
            int ans{MAX};
            while(l <= r){
                int m{(l + r) / 2};
                if(BIT.f(0, m) < b){
                    l = m + 1;
                }
                else{
                    r = m - 1;
                    ans = min(ans, m);
                }
            }
            cout << ans << "\n";
            BIT.add(ans, -1);
        }
    }
}

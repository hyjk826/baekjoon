// 2022-09-20
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vp vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i].first >> vec[i].second;
        }
        sort(vec.begin(), vec.end());
        binary_indexed_tree<int> BIT(10020);
        BIT.add(vec[0].second, 1);
        int k{0};
        int ans{1};
        for(int i{1}; i < n; ++i){
            while(k < i){
                if(vec[i].first - vec[k].first > 10){
                    BIT.add(vec[k].second, -1);
                    k++;
                }
                else break;
            }
            BIT.add(vec[i].second, 1);
            for(int j{vec[i].second - 10}; j <= vec[i].second; ++j){
                ans = max(ans, BIT.f(j, j + 10));
            }
        }
        cout << ans << "\n";
    }
}
	


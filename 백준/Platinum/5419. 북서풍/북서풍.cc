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
        vi A;
        for(int i{0}; i < n; ++i){
            A.push_back(vec[i].second);
        }
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        for(int i{0}; i < n; ++i){
            vec[i].second = lower_bound(A.begin(), A.end(), vec[i].second) - A.begin();
        }
        binary_indexed_tree<int> BIT((int)A.size() + 10);
        ll ans{1LL * n  * (n - 1) / 2};
        for(int i{0}; i < n; ++i){
            vi A;
            A.push_back(vec[i].second);
            while(i < n - 1 && vec[i].first == vec[i + 1].first){
                A.push_back(vec[i + 1].second);
                i++;
            }
            for(auto& i : A){
                if(i - 1 >= 0){
                    ans -= BIT.f(0, i - 1);
                }
            }
            for(auto& i : A){
                BIT.add(i, 1);
            }
        }
        cout << ans << "\n";
    }
}

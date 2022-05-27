// 2022-05-27
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
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
};

int main(){
    fastio;
    binary_indexed_tree<int> BIT(1000001);
    int n;
    cin >> n;
    while(n--){
        int q;
        cin >> q;
        int a, b;
        if(q == 2){
            cin >> a >> b;
            BIT.add(a, b);
        } 
        else{
            cin >> a;
            int l{1}, r{1000000};
            int ans{MAX};
            while(l <= r){
                int m{(l + r) / 2};
                if(BIT.sum(m + 1) >= a){
                    ans = min(ans, m);
                    r = m - 1;
                }
                else l = m + 1;
            }
            BIT.add(ans, -1);
            cout << ans << "\n";
        }
    }
}
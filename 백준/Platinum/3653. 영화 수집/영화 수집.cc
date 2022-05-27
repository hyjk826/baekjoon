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
};

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        binary_indexed_tree<int> BIT(n + q);
        vi index(n);
        for(int i{q}; i < n + q; ++i){
            BIT.add(i, 1);
            index[i - q] = i;
        }
        int a = q - 1;
        for(int i{0}; i < q; ++i){
            int k;
            cin >> k;
            k--;
            cout << BIT.sum(index[k]) << " ";
            BIT.add(index[k], -1);
            index[k] = a;
            BIT.add(a--, 1);
        }
        cout << "\n";
    }
}
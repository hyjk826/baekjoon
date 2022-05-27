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

struct st{
    int x, i, num;
};

int main(){
    fastio;
    int n;
    cin >> n;
    binary_indexed_tree<int> BIT(n);
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x;
        vec[i].i = i;
    }    
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        return a.x > b.x;
    });
    for(int i{0}; i < n; ++i){
        vec[i].num = i;
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        return a.i < b.i;
    });
    for(int i{0}; i < n; ++i){
        cout << BIT.sum(vec[i].num) + 1 << "\n";
        BIT.add(vec[i].num, 1);
    }
}
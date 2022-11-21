// 2022-11-21
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
	int n;
    cin >> n;
    vi A;
    vi B;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        A.push_back(a);
        B.push_back(a);
    }               
    int q;
    cin >> q;
    vector<vi> vec(q);
    for(int i{0}; i < q; ++i){
        int a, b, c;
        cin >> a;
        vec[i].push_back(a);
        if(a == 1){
            cin >> b;
            A.push_back(b);
            vec[i].push_back(b);
        }
        else{
            cin >> b >> c;
            vec[i].push_back(b);
            vec[i].push_back(c);
        }
    }    
    int cnt{0};
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    binary_indexed_tree<int> BIT((int)A.size());
    for(auto& i : B){
        int a = lower_bound(A.begin(), A.end(), i) - A.begin();
        BIT.add(a, 1);
    }   
    for(int i{0}; i < q; ++i){
        if(vec[i][0] == 1){
            int a = lower_bound(A.begin(), A.end(), vec[i][1]) - A.begin();
            BIT.add(a, 1);
        }
        else{
            int a = vec[i][1];
            int b = vec[i][2];
            int r = upper_bound(A.begin(), A.end(), b) - A.begin();
            r--;
            int l = lower_bound(A.begin(), A.end(), a) - A.begin();
            if(r < l){
                cout << 0 << "\n";
            }
            else{
                cout << b - a + 1 - BIT.f(l, r) << "\n";
            }
        }
    }
}
	


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

struct query{
    ll op, a, b;
};

int main(){
	fastio;
    int n;
    cin >> n;
    binary_indexed_tree<int> BIT((int)4e5 + 10);
    set<ll> st;
    vector<query> A(n);
    vl B;
    bool flag = false;
    for(int i{0}; i < n; ++i){
        ll op, a, b;
        cin >> op;
        ll k{1};
        if(op == 1){
            cin >> a >> b;
            if(a < 0) k *= -1;
            if(b < 0) k *= -1;
            if(a == 0) {
                A[i] = {op, a, b};
                continue;
            }
            if(b % a == 0){
                B.push_back(b / a + 1);
            }
            else if(k == -1){
                B.push_back(-abs(b) / abs(a));
            }
            else{
                k = (abs(b) + abs(a) - 1) / abs(a);
            }
            A[i] = {op, a, b};
        }
        else{
            cin >> a;
            B.push_back(-a);
            A[i] = {op, a, 0};
        }
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    int cnt{0};
    for(int i{0}; i < n; ++i){
        if(A[i].op == 1){
            ll a = A[i].a;
            ll b = A[i].b;
            flag |= (a == 0 && b == 0);
            if(flag) continue;
            if(a == 0){
                if(b < 0) cnt++;
            }
            else{
                ll k{1};
                if(a < 0) {
                    k *= -1;
                    cnt++;
                }
                if(b < 0) k *= -1;
                if(b % a == 0) {
                    st.insert(b / a);
                    k = b / a + 1;
                }
                else if(k == -1){
                    k = -abs(b) / abs(a);
                }
                else{
                    k = (abs(b) + abs(a) - 1) / abs(a);
                }
                k = lower_bound(B.begin(), B.end(), k) - B.begin();
                BIT.add(k, 1);
            }
        }
        else{
            if(flag || st.count(-A[i].a)) cout << 0 << "\n";
            else{
                int k = lower_bound(B.begin(), B.end(), -A[i].a) - B.begin();
                if((cnt + BIT.f(0, k)) & 1) cout << "-\n";
                else cout << "+\n";
            }
        }
    }

}

// 2022-07-29
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

struct st{
    int k, l, r, num;
};

int main() {
	fastio;
    int n;
    cin >> n;
    binary_indexed_tree<ll> BIT(n + 1);
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        BIT.add(i, vec[i]);
    }
    int q;
    cin >> q;
    vp A;
    vector<st> B;
    int cnt{0};
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int b, c;
            cin >> b >> c;
            b--;
            A.push_back({b, c});
        }
        else{
            int b, c, d;
            cin >> b >> c >> d;
            c--;
            d--;
            B.push_back({b, c, d, cnt});
            cnt++;
        }
    }
    vl ans(cnt);
    sort(B.begin(), B.end(), [&](st a, st b){
        return a.k < b.k;
    });
    int index{0};
    while(index < (int)B.size() && B[index].k == 0){
        ans[B[index].num] = BIT.f(B[index].l, B[index].r);
        index++;
    }
    for(int i{0}; i < (int)A.size(); ++i){
        BIT.add(A[i].first, A[i].second - vec[A[i].first]);
        vec[A[i].first] = A[i].second;
        while(index < (int)B.size() && B[index].k == i + 1){
            ans[B[index].num] = BIT.f(B[index].l, B[index].r);
            index++;
        }
    }
    for(auto& i : ans) cout << i << "\n";
}


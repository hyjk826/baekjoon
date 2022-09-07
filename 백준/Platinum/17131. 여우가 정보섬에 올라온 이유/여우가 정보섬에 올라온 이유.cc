// 2022-09-06
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
    int n;
    cin >> n;
    vp vec(n);
    map<int, int> mp;
    set<int> st;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        mp[vec[i].first]++;
        st.insert(vec[i].second);
    }
    sort(vec.begin(), vec.end());
    map<int, int> mm;
    int k{0};
    for(auto& i : st){
        mm[i] = k++;
    }
    for(int i{0}; i < n; ++i){
        vec[i].second = mm[vec[i].second];
    }
    map<int, int> mp2;
    map<int, int> mp3;
    vi a(n), b(n);
    binary_indexed_tree<int> A(400001), B(400001);
    for(int i{0}; i < n; ++i){
        a[i] = A.f(vec[i].second + 1, 400000);
        mp2[vec[i].first]++;
        if(mp2[vec[i].first] == mp[vec[i].first]){
            for(int j{i}; j > i - mp[vec[i].first]; --j){
                A.add(vec[j].second, 1);
            }
        }
    }
    for(int i{n - 1}; i >= 0; --i){
        b[i] = B.f(vec[i].second + 1, 400000);
        mp3[vec[i].first]++;
        if(mp3[vec[i].first] == mp[vec[i].first]){
            for(int j{i}; j < i + mp[vec[i].first]; ++j){
                B.add(vec[j].second, 1);                
            }
        }
    }
    ll ans{0};
    for(int i{0}; i < n; ++i){
        ans += 1LL * a[i] * b[i];
        ans %= MOD;
    }
    cout << ans;
}
	


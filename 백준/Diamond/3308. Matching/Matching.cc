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
    if(a < 0 || b < 0) return 0;
    if(a == 0) return sum(b + 1);
    else return sum(b + 1) - sum(a);
  }
};

vi L, R;

vi fail_func(vi& A){
    int n = (int)A.size();
    int j{0};
    vi fail(n);
    L.resize(n); R.resize(n);
    binary_indexed_tree<int> BIT(n + 10);
    for(int i{0}; i < n; ++i){
        L[i] = BIT.f(0, A[i] - 1);
        R[i] = BIT.f(A[i] + 1, n - 1);
        BIT.add(A[i], 1);
    }
    fill(BIT.BIT.begin(), BIT.BIT.end(), 0);
    for(int i{1}; i < n; ++i){
        while(j && !((L[j] == BIT.f(0, A[i] - 1)) && (R[j] == BIT.f(A[i] + 1, n - 1)))){
            for(int k{i - j}; k < i - fail[j - 1]; ++k){
                BIT.add(A[k], -1);
            }
            j = fail[j - 1];
        }
        if((L[j] == BIT.f(0, A[i] - 1)) && (R[j] == BIT.f(A[i] + 1, n - 1))){
            BIT.add(A[i], 1);
            fail[i] = ++j;
        }
    }
    return fail;
}

vi kmp(vi& A, vi& B){
    int n = (int)A.size();
    int m = (int)B.size();
    vi fail = fail_func(A);
    binary_indexed_tree<int> BIT(m + 10);
    int j{0};
    vi ret;
    for(int i{0}; i < m; ++i){
        while(j && !((L[j] == BIT.f(0, B[i] - 1)) && (R[j] == BIT.f(B[i] + 1, m - 1)))){
            for(int k{i - j}; k < i - fail[j - 1]; ++k){
                BIT.add(B[k], -1);
            }
            j = fail[j - 1];
        }
        if((L[j] == BIT.f(0, B[i] - 1)) && (R[j] == BIT.f(B[i] + 1, m - 1))){
            if(j == n - 1){
                ret.push_back(i - n + 1);
                for(int k{i - j}; k < i - fail[j] + 1; ++k){
                    BIT.add(B[k], -1);
                }
                j = fail[j];
            }
            else j++;
            BIT.add(B[i], 1);
        }
    }
    return ret;
}


int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vp tmp(n);
    vi B(m);
    for(int i{0}; i < n; ++i){
        cin >> tmp[i].first;
        tmp[i].second = i;
    }
    sort(tmp.begin(), tmp.end());
    vi A;
    for(auto& i : tmp){
        A.push_back(i.second);
    }
    for(auto& i : B) cin >> i;
    vi C = A; vi D = B;
    sort(C.begin(), C.end()); C.erase(unique(C.begin(), C.end()), C.end());
    sort(D.begin(), D.end()); D.erase(unique(D.begin(), D.end()), D.end());
    for(auto& i : A) i = lower_bound(C.begin(), C.end(), i) - C.begin();
    for(auto& i : B) i = lower_bound(D.begin(), D.end(), i) - D.begin();
    vi res = kmp(A, B);
    cout << res.size() << "\n";
    for(auto& i : res) cout << i + 1 << " ";
}   

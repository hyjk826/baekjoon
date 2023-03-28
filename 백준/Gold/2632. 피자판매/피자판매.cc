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

int main(){
	fastio;
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vi A(n + 1), B(m + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
        A.push_back(A[i]);
    }
    for(int i{1}; i <= m; ++i){
        cin >> B[i];
        B.push_back(B[i]);
    }
    for(int i{1}; i <= 2 * n; ++i){
        A[i] += A[i - 1];
    }
    for(int i{1}; i <= 2 * m; ++i){
        B[i] += B[i - 1];
    }
    vi X, Y;
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < i + n; ++j){
            int a = A[j] - A[i];
            if(a <= k) X.push_back(a);
        }   
    }
    for(int i{0}; i < m; ++i){
        for(int j{i + 1}; j < i + m; ++j){
            int a = B[j] - B[i];
            if(a <= k) Y.push_back(a);
        }
    }
    X.push_back(A[n]);
    Y.push_back(B[m]);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll ans{0};
    ans += upper_bound(X.begin(), X.end(), k) - lower_bound(X.begin(), X.end(), k);
    ans += upper_bound(Y.begin(), Y.end(), k) - lower_bound(Y.begin(), Y.end(), k);
    for(auto& i : X){
        ans += upper_bound(Y.begin(), Y.end(), k - i) - lower_bound(Y.begin(), Y.end(), k - i);
    }
    cout << ans;
}

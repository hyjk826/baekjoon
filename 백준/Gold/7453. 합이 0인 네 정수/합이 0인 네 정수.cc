// 2022-07-26
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi A(n), B(n), C(n), D(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vi X, Y;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            X.push_back(A[i] + B[j]);
            Y.push_back(C[i] + D[j]);      
        }
    }
    ll ans{0};
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for(int i{0}; i < (int)X.size(); ++i){
        ans += upper_bound(Y.begin(), Y.end(), -X[i]) - lower_bound(Y.begin(), Y.end(), -X[i]);
    }
    cout << ans;
}


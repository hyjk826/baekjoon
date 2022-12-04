// 2022-12-04
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


int main() {
	fastio;
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    vi A(n, 1), B(n, 1);
    A[0] = 1;
    for(int i{1}; i < n; ++i){
        for(int j{i - 1}; j >= 0; --j){
            if(vec[j] > vec[i]) A[i] = max(A[i], A[j] + 1);
        }
    }
    B[n - 1] = 1;
    for(int i{n - 2}; i >= 0; --i){
        for(int j{i + 1}; j < n; ++j){
            if(vec[j] > vec[i]) B[i] = max(B[i], B[j] + 1);
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        ans = max(ans, A[i] + B[i] - 1);
    }
    cout << ans;
}
	

// 2022-11-20
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
    int n, m, x;
    cin >> n >> m >> x;
    vi A(n), B(m);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < m; ++i){
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int l{0}, r{min(m, n)};
    int ans{0};
    while(l <= r){
        int mid{(l + r) / 2};
        ll sum{0};        
        for(int i{0}; i < mid; ++i){
            sum += max(0, A[i] - B[i + (m - mid)]);
        }
        if(sum <= x){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
}
	


// 2022-07-28
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
    vi A(n), B(n);
    for(int i{0}; i < n; ++i) cin >> A[i];
    for(int i{0}; i < n; ++i) cin >> B[i];
    int ans{0};
    for(int i{0}; i < (1 << n); ++i){
        int sum{0};
        int c{0};
        for(int j{0}; j < n; ++j){
            if(i >> j  & 1){
                sum += A[j];
                c += B[j];
            }
        }
        if(sum < 100){
            ans = max(ans, c);
        }
    }
    cout << ans;
}


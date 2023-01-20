// 2023-01-21
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
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int ans{0};
    for(int i{0}; i < (1 << n); ++i){
        int sum{0};
        int a{0};
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1) sum += vec[j];
            if(sum >= k){
                a += sum - k;
                sum = 0;
            }
        }
        ans = max(ans, a);
    }
    cout << ans;
}

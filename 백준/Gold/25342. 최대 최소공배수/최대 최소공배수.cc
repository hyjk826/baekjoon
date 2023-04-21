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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}


int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vl A;
        for(int i{max(1, n - 5)}; i <= n; ++i){
            A.push_back(i);
        }
        ll ans{0};
        for(int i{0}; i < (int)A.size(); ++i){
            for(int j{i + 1}; j < (int)A.size(); ++j){
                for(int k{j + 1}; k < (int)A.size(); ++k){
                    ll a = lcm(A[j], A[k]);
                    ans = max(ans, lcm(A[i], a));
                }
            }
        }
        cout << ans << "\n";
    }
}

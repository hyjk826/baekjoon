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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
	fastio;	
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi prime(1000001);
    prime[1] = 1;
    for(int i{2}; i <= (int)1e6; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= (int)1e6; j += i){
                prime[j] = 1;
            }
        }
    }
    ll ans{1};
    int cnt{0};
    for(int i{0}; i < n; ++i){
        if(prime[vec[i]] == 0){
            ans = lcm(ans, vec[i]);
            cnt++;
        }
    }
    if(cnt == 0) cout << -1;
    else cout << ans;
}
	


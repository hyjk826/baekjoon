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
    vi prime(2000001);
    prime[1] = 1;
    for(ll i{2}; i <= 2000000; ++i){
        if(prime[i] == 0){
            for(ll j{i * i}; j <= 2000000; j += i) prime[j] = 1;
        }
    }
	int n;
    cin >> n;
    vi vec(n);
    int mx{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        mx = max(mx, vec[i]);
    }
    int ans{1};
    vi ch(2000001);
    for(int i{2}; i <= mx; ++i){
        if(prime[i]) continue;
        for(int j{0}; j < n; ++j){
            ch[vec[j] % i]++;
            ans = max(ans, ch[vec[j] % i]);
        }
        for(int j{0}; j < n; ++j){
            ch[vec[j] % i]--;
        }
        
    }
    cout << ans;
}
	


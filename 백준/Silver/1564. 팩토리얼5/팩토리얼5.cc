// 2022-12-18
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
	int n;
    cin >> n;
    ll k{1};
    for(int i{1}; i <= n; ++i){
        k *= i;
        while(k % 10 == 0) k /= 10;
        k %= (ll)1e12;
    }
    int ans = k % (int)1e5;
    cout << string(5 - (int)to_string(ans).size(), '0');
    cout << ans;
}
	

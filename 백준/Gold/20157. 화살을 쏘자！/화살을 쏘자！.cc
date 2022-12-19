// 2022-12-20
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
	int n;
    cin >> n;
    int ans{0};
    map<pi, int> mp;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) ans++;
        else{
            int g = gcd(abs(a), abs(b));
            a /= g;
            b /= g;
            mp[{a, b}]++;
        }
    }
    int mx{0};
    for(auto& i : mp){
        mx = max(mx, i.second);
    }
    ans += mx;
    cout << ans;
}
	

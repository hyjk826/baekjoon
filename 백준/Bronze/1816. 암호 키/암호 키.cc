// 2022-12-30
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
    int t;
    cin >> t;
    function<bool(ll)> f = [&](ll n){
        for(int i{2}; i <= (int)1e6; ++i){
            if(n % i == 0) return false;
        }
        return true;
    };
    while(t--){
        ll n;
        cin >> n;
        if(f(n)) cout << "YES\n";
        else cout << "NO\n";
    }
}

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
    int tt;
    cin >> tt;
    while(tt--){
        ll n, s, t;
        cin >> n >> s >> t;
        ll ans{0};
        while(n){
            if(n & 1){
                ans += s;
                n--;
            }
            else{
                if(n > 2 * t / s){
                    n /= 2;
                    ans += t;
                }
                else{
                    ans += n * s;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}

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
    for(int T{1};;++T){
        int n;
        cin >> n;
        if(n == 0) break;
        ll ans{0};
        ll k{1};
        for(int i{1};;++i){
            k *= 5;
            if(k > n) break;
            ans += n / k;
        }
        cout << "Case #" << T << ": " << ans << "\n";
    }
}

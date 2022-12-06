// 2022-12-04
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
	ll n;
    cin >> n;
    string str;
    int sz = to_string(n).size();
    for(int i{0}; i < 10; ++i) str += char('0' + i);
    vl A;
    ll ans{(ll)1e15};
    do{
        
        for(int i{sz - 1}; i <= sz + 1; ++i){
            if(i <= 0) continue;
            ll k = stoll(str.substr(0, i));    
            if(abs(ans - n) > abs(k - n)) ans = k;
            else if(abs(ans - n) == abs(k - n)) ans = min(ans, k);
        }
    }while(next_permutation(str.begin(), str.end()));
    cout << ans;
}
	

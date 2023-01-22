// 2023-01-22
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
    while(t--){
        int n;
        cin >> n;
        priority_queue<ll, vl, greater<ll> > pQ;
        for(int i{0}; i < n; ++i){
            ll a;
            cin >> a;
            pQ.push(a);
        }
        ll ans{1};
        while(pQ.size() >= 2){
            ll a = pQ.top();
            pQ.pop();
            ll b = pQ.top();
            pQ.pop();
            ll k = a * b;
            pQ.push(k);
            k %= MOD;
            ans *= k;
            ans %= MOD;            
        }
        cout << ans << "\n";
    }
}

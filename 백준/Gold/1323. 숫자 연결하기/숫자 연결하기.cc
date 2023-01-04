// 2023-01-04
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
    ll n, k;
    cin >> n >> k;
    vi ch(k);
    ll sz = to_string(n).size();
    ll a{1};
    ll b{0};
    for(int i{0}; i < sz; ++i) a *= 10;
    for(int i{1};;++i){
        b = (b * a + n) % k;
        if(b == 0){
            cout << i;
            return 0;
        }
        if(ch[b]){
            cout << -1;
            return 0;
        }
        ch[b] = 1;
    }
}

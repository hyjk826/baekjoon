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
    ll n;
    cin >> n;
    if(n == 0){
        cout << 0; return 0;
    }
    int ans{1};
    ll k{1};
    while(k < n){
        ans++;
        k *= 2;
    }
    cout << ans;
}

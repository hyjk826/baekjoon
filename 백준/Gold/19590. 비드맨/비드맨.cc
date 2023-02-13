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
    ll mx{0};
    vl vec(n);
    ll sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
        mx = max(mx, vec[i]);
    }
    if(mx * 2 >= sum) cout << 2 * mx - sum;
    else{
        if(sum & 1) cout << 1;
        else cout << 0;
    }
}

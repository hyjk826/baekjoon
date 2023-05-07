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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        if(vec[i] & 1) vec[i] = 1;
        else vec[i] = 0;
    }
    int cnt{0};
    ll sum{0};
    ll ans{LLONG_MAX};
    for(int i{0}; i < n; ++i){
        if(vec[i]) cnt++;
        else sum += cnt;
    }
    ans = min(ans, sum);
    sum = 0;
    cnt = 0;
    for(int i{0}; i < n; ++i){
        if(vec[i] == 0) cnt++;
        else sum += cnt;
    }
    ans = min(ans, sum);
    cout << ans;
}

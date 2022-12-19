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

int main(){
	fastio;
	int n;
    cin >> n;
    vi vec(n);
    int ans{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        ans ^= vec[i];
    }
    vi pre(n), post(n);
    pre[0] = vec[0];
    post[n - 1] = vec[n - 1];
    for(int i{1}; i < n; ++i){
        pre[i] = pre[i - 1] ^ vec[i];
    }
    for(int i{n - 2}; i >= 0; --i){
        post[i] = post[i + 1] ^ vec[i];
    }
    for(int i{0}; i < n; ++i){
        if(i == 0) ans = max(ans, post[1]);
        else if(i == n - 1) ans = max(ans, pre[n - 2]);
        else ans = max(ans, pre[i - 1] ^ post[i + 1]);
    }
    cout << ans << ans;
}

	

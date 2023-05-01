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
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        if(a == 1) vec[i] = 1;
        else vec[i] = -1;
        vec[i]+= vec[i - 1];
    }
    vi mx = vec;
    vi mn = vec;
    for(int i{n - 1}; i >= 0; --i){
        mx[i] = max(mx[i], mx[i + 1]);
        mn[i] = min(mn[i], mn[i + 1]);
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        ans = max(ans, abs(vec[i] - mx[i + 1]));
        ans = max(ans, abs(vec[i] - mn[i + 1]));
    }
    cout << ans;
}

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
    ll ans{0};
    int n, k;
    cin >> n >> k;
    vi vec(20);
    vec[0] = 1 % k;
    for(int i{1}; i < 20; ++i){
        vec[i] = (vec[i - 1] * 10) % k;
    }
    for(int i{1}; i <= n; ++i){
        int temp = i;
        int cnt{0};
        while(temp){
            temp /= 10;
            cnt++;
        }
        temp = i;
        ans = (ans * vec[cnt] + temp) % k;
    }
    cout << ans;
}

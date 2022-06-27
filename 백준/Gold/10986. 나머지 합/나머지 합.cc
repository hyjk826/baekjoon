// 2022-06-28
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, k;
    cin >> n >> k;
    vi ch(k);
    ch[0] = 1;
    ll sum{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        sum += a;
        ch[sum % k]++;
    }
    ll ans{0};
    for(int i{0}; i < k; ++i){
        ans += 1.0 * ch[i] * (ch[i] - 1) / 2;
    }
    cout << ans;
}

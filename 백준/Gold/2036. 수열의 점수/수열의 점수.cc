// 2022-09-21
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vi minus;
    vi plus;
    int one{0};
    int cnt{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a < 0) minus.push_back(a);
        else if(a == 0) cnt++;
        else if(a == 1) one++;
        else plus.push_back(a);
    }
    ll ans{0};
    sort(plus.rbegin(), plus.rend());
    int sz = (int)plus.size();
    for(int i{0}; i + 1 < sz; i += 2){
        ans += 1LL * plus[i] * plus[i + 1];
    }
    if((int)plus.size() & 1) ans += plus.back();
    sort(minus.begin(), minus.end());
    for(int i{0}; i + 1 < (int)minus.size(); i += 2){
        ans += 1LL * minus[i] * minus[i + 1];
    }
    if(cnt == 0 && minus.size() % 2 == 1) ans += minus.back();
    ans += one;
    cout << ans;
}
	


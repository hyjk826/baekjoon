// 2023-01-03
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

vi ch(2000001);

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        ch[a]++;
    }
    ll ans{0};
    for(int i{1}; i <= 2000000; ++i){
        ll sum{0};
        for(int j{i}; j <= 2000000; j += i){
            sum += 1LL * ch[j] * i;
        }
        if(sum == i) continue;
        ans = max(ans, sum);
    }
    cout << ans;
}

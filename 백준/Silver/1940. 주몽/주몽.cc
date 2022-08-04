// 2022-08-03
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
	int n, m;
    cin >> n >> m;
    map<int, int> mp;
    ll ans{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        ans += mp[m - a];
        mp[a]++;
    }
    cout << ans;
}
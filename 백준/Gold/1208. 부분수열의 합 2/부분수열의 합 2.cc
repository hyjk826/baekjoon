// 2022-09-14
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
    int n, s;
    cin >> n >> s;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    int h = n / 2;
    map<int, int> mp1, mp2;
    for(int i{0}; i < (1 << h); ++i){
        int sum{0};
        for(int j{0}; j < h; ++j){
            if((i >> j) & 1){
                sum += vec[j];
            }
        }
        mp1[sum]++;
    }
    for(int i{0}; i < (1 << (n - h)); ++i){
        int sum{0};
        for(int j{0}; j < n - h; ++j){
            if((i >> j) & 1){
                sum += vec[j + h];
            }
        }
        mp2[sum]++;
    }
    ll ans{0};
    for(auto& i : mp1){
        if(mp2.count(s - i.first)){
            ans += 1LL * i.second * mp2[s - i.first];
        }
    }
    if(s == 0) ans--;
    cout << ans;
}
	


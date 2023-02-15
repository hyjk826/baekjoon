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
    int n, l, k;
    cin >> n >> l >> k;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vi ch(n);
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(k == 0) break;
        if(vec[i].second <= l) {
            ans += 140;
            ch[i] = 1;
            k--;
        }
    }
    for(int i{0}; i < n; ++i){
        if(k == 0) break;
        if(ch[i]) continue;
        if(vec[i].first <= l){
            ans += 100;
            k--;
        }
    }
    cout << ans;
}

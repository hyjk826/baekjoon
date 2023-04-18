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
    int n, k;
    cin >> n >> k;
    vi vec(n + 1);
    vl ch(n + 1);
    int idx{0};
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        if(vec[i] == k) idx = i;
        if(vec[i] > k) ch[i] = 1;
        else if(vec[i] < k) ch[i] = -1;
        ch[i] += ch[i - 1];
    }
    map<int,int> mp;
    for(int i{0}; i < idx; ++i){
        mp[ch[i]]++;
    }
    ll ans{0};
    for(int i{idx}; i <= n; ++i){
        if(mp.count(ch[i])) ans += mp[ch[i]];
    }
    cout << ans;
}

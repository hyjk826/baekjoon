// 2022-10-11
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
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    map<int, int> mp;
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a = vec[i].first;
        int b = vec[i].second;
        auto it = mp.upper_bound(a - s);
        if(it == mp.begin()) mp[a] = max(mp[a], b);
        else{
            it--;
            mp[a] = max(mp[a], it->second + b);
        }
        ans = max(ans, mp[a]);
        it = mp.lower_bound(a);
        if(it != mp.begin()) mp[a] = max(mp[a], prev(it)->second);
    }
    cout << ans;
}
	


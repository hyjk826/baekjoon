// 2022-09-08
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
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    unordered_map<int, int> mp;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < k; ++i){
        vec.push_back(vec[i]);
        mp[vec[i]]++;
    }
    int ans;
    if(mp.count(c) && mp[c] >= 1) ans = (int)mp.size();
    else ans = (int)mp.size() + 1;
    for(int i{k}; i < (int)vec.size(); ++i){
        mp[vec[i]]++;
        mp[vec[i - k]]--;
        if(mp[vec[i - k]] == 0){
            mp.erase(vec[i - k]);
        }
        if(mp.count(c) && mp[c] >= 1) ans = max(ans, (int)mp.size());
        else ans = max(ans, (int)mp.size() + 1);
    }
    cout << ans;
}
	


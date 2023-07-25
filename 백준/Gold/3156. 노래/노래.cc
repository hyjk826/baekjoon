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

void solve(){
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i{0}; i < n; ++i){
        int m, k;
        string od;
        cin >> m >> od >> k;
        for(int j{0}; j < m; ++j){
            string str;
            cin >> str;
            if(!mp.count(str)) mp[str] = k;
            else mp[str] = min(mp[str], k);
        }
    }
    vi cnt((int)mp.size() + 1);
    for(auto& i : mp){
        cnt[i.second]++;
    }
    for(int i{1}; i <= (int)mp.size(); ++i){
        cnt[i] += cnt[i - 1];
    }
    vector<pair<int, string> > ans;
    for(auto& i : mp){
        if(cnt[i.second - 1] == i.second - 1){
            ans.push_back({i.second, i.first});
        }
    }
    sort(ans.begin(), ans.end(), [&](pair<int, string>& x, pair<int, string>& y){
        return x.first < y.first;
    });
    for(auto& i : ans) cout << i.first << " " << i.second << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

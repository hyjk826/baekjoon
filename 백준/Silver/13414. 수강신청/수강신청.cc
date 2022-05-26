// 2022-05-24
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
    map<string, int> mp;
    for(int i{0}; i < m; ++i){
        string str;
        cin >> str;
        mp[str] = i;
    }
    vector<pair<int, string> >  ans;
    for(auto& i : mp){
        ans.push_back({i.second, i.first});
    }
    sort(ans.begin(), ans.end());
    for(int i{0}; i < min(n, (int)mp.size()); ++i){
        cout << ans[i].second << "\n";
    }
}
// 2022-09-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> mp;
        for(int i{0}; i < n; ++i){
            string s, t;
            cin >> s >> t;
            mp[t]++;
        }
        ll ans{1};
        for(auto& i : mp){
            ans *= (1 + i.second);
        }
        cout << ans - 1 << "\n";
    }
}
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
	string s, t;
    cin >> s >> t;
    vector<vi> g(26);
    for(int i{0}; i < (int)t.size(); ++i){
        g[t[i]- 'a'].push_back(i);
    }
    int ans{1};
    int k{-1};
    for(int i{0}; i < (int)s.size(); ++i){
        int c = s[i] - 'a';
        auto it = upper_bound(g[c].begin(), g[c].end(), k);
        if(it == g[c].end()){
            if(k == -1){
                cout << -1; return 0;
            }
            ans++;
            i--;
            k = -1;
        }
        else{
            k = it - g[c].begin();
        }
    }
    cout << ans;
}

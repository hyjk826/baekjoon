// 2023-01-19
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
    int n;
    cin >> n;
    map<int, set<int>> mp;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    vi path(n);
    for(int i{0}; i < n; ++i){
        cin >> path[i];
    }
    int idx{0};
    vi A;
    function<void(int)> dfs = [&](int cur){
        A.push_back(cur);
        idx++;
        while(mp[cur].count(path[idx])){
            dfs(path[idx]);
        }
    };
    dfs(path[0]);
    if(path[0] == 1 && A.size() == n) cout << 1;
    else cout << 0;
}

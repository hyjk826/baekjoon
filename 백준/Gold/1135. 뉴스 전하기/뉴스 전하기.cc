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
    vector<vi> g(n);
    vi degree(n);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(i){
            g[a].push_back(i);
        }
    }
    function<int(int)> dfs = [&](int cur){
        vi vec;
        int mx{0};
        for(auto& i : g[cur]){
            vec.push_back(dfs(i));
        }
        sort(vec.rbegin(), vec.rend());
        for(int i{0}; i < (int)vec.size(); ++i){
            mx = max(mx, vec[i] + i + 1);
        }
        return mx;
    };
    cout << dfs(0);
}

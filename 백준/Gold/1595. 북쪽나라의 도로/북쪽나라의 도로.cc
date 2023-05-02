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
    int a, b, c;
    vector<vp> g(10001);
    while(cin >> a >> b >> c){
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int mx{0};
    int idx{1};
    function<void(int,int,int)> f = [&](int cur, int pre, int sum){
        if(mx < sum){
            mx = sum;
            idx = cur;
        }
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            f(i.first, cur, sum + i.second);
        }
    };
    f(1, -1, 0);
    mx = 0;
    f(idx, -1, 0);
    cout << mx;
}

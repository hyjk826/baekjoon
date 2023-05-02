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
    int n, R;
    cin >> n >> R;
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int a{0}, b{0};
    bool ok = false;
    int mx{0};
    function<void(int,int, int)> f = [&](int cur, int pre, int sum){
        mx = max(mx, sum);
        if(!ok && (g[cur].size() >= 3 || (cur == R && g[cur].size() >= 2))) {
            a = sum;
            sum = 0;
            ok = true;
        }
        if(ok) b = max(b, sum);
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            f(i.first, cur, sum + i.second);
        }
    };  
    f(R, -1, 0);
    if(!ok) a = mx;
    cout << a << " " << b;
}

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
    while(cin >> n){
        if(n == 0) break;
        vector<vp> g(n);
        for(int i{0}; i < n - 1; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        vi sub(n);
        ll sum{0};
        function<void(int,int)> dfs = [&](int cur, int pre){
            sub[cur] = 1;
            for(auto& i : g[cur]){
                if(i.first == pre) continue;
                dfs(i.first, cur);
                sub[cur] += sub[i.first];
                sum += 1LL * i.second * sub[i.first];
            }
        };
        dfs(0, -1);
        vl A(n);
        A[0] = sum;
        function<void(int,int)> dfs2 = [&](int cur, int pre){
            for(auto& i : g[cur]){
                if(i.first == pre) continue;
                A[i.first] = A[cur] + 1LL * i.second * (n - 2 * sub[i.first]);
                dfs2(i.first, cur);
            }
        };
        dfs2(0, -1);
        cout << *min_element(A.begin(), A.end()) << "\n";
    }
}

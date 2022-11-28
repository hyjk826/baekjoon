// 2022-11-28
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


int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi ch(n + 1);
    int ans{0};
    int comp{0};
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        comp++;
        int cnt{0};
        queue<int> Q;
        Q.push(i);
        ch[i] = 1;
        int a{0};
        while(!Q.empty()){
            int v{Q.front()};
            Q.pop();
            a++;
            cnt += (int)g[v].size();
            for(auto& j : g[v]){
                if(ch[j] == 0){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
        int k = cnt / 2;
        ans += max(0, k - (a - 1));
    }
    ans += comp - 1;
    cout << ans;
}
	

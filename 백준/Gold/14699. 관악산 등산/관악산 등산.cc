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
    int n, m;
    cin >> n >> m;
    vi H(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> H[i];
    }
    vector<vi> g(n + 1);
    vi degree(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b; 
        cin >> a >> b;
        if(H[a] == H[b]) continue;
        if(H[a] > H[b]){ 
            g[a].push_back(b);
            degree[b]++;
        }
        else {
            g[b].push_back(a);
            degree[a]++;
        }
    }
    queue<int> Q;
    vi ans(n + 1, 1);
    for(int i{1}; i <= n; ++i){
        if(degree[i] == 0) {
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            ans[i] = max(ans[i], ans[x] + 1);
            degree[i]--;
            if(degree[i] == 0){
                Q.push(i);
            }
        }
    }
    for(int i{1}; i <= n; ++i) cout << ans[i]<< "\n";
}

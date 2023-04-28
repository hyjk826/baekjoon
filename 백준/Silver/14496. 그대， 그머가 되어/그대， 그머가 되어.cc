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
    int a, b;
    cin >> a >> b;
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> Q;
    Q.push(a);
    vi dist(n + 1, -1);
    dist[a] = 0;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        if(x == b){
            cout << dist[x]; return 0;
        }
        for(auto& i : g[x]){
            if(dist[i] == -1){
                dist[i] = dist[x] + 1;
                Q.push(i);
            }
        }
    }
    cout << -1;
}

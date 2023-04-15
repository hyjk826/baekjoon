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
    int n, m, q;
    cin >> n >> m >> q;
    vp edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].first >> edge[i].second;
    }
    vi ch(m);
    vp query(q);
    for(int i{0}; i < q; ++i){
        char op; int a;
        cin >> op >> a;
        if(op == 'U') {
            a--;
            query[i] = {0, a};
            ch[a] = 1;
        }
        else query[i] = {1, a};
    }
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        if(ch[i]) continue;
        int a = edge[i].first;
        int b = edge[i].second;
        g[a].push_back(b);
    }
    vi ans;
    vi dist(n + 1, MAX);
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dist[i] > dist[x] + 1){
                dist[i] = dist[x] + 1;
                Q.push(i);
            }
        }
    }
    for(int i{q - 1}; i >= 0; --i){
        if(query[i].first == 0){
            int idx = query[i].second;
            int a = edge[idx].first;
            int b = edge[idx].second;
            g[a].push_back(b);
            Q.push(a);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& j : g[x]){
                    if(dist[j] > dist[x] + 1){
                        dist[j] = dist[x] + 1;
                        Q.push(j);
                    }
                }
            }
        }
        else{
            int a = query[i].second;
            if(dist[a] == MAX) ans.push_back(-1);
            else ans.push_back(dist[a]);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << "\n";
}

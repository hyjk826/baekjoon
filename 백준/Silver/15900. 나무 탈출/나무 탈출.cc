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
	int n;
    cin >> n;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi dist(n + 1, -1);
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dist[i] == -1){
                dist[i]= dist[x] + 1;
                Q.push(i);
            }
        }
    }
    int sum{0};
    for(int i{2}; i <= n; ++i){
        if(g[i].size() == 1) sum += dist[i];
    }
    if(sum & 1) cout << "Yes";
    else cout << "No";
}

// 2022-09-12
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<vp> g(100001);
int n;

pi bfs(int s){
    vi dis(n + 1, -1);
    dis[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dis[i.first] == -1){
                dis[i.first] = dis[x] + i.second;
                Q.push(i.first);
            }
        }
    }
    int mx{1};
    for(int i{1}; i <= n; ++i){
        if(dis[i] > dis[mx]){
            mx = i;
        }
    }
    return {mx, dis[mx]};
}

int main() {
	fastio;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        while(1){
            int b, c;
            cin >> b;
            if(b == -1) break;
            cin >> c;
            g[a].push_back({b, c});
        }
    }    
    pi A = bfs(1);
    pi B = bfs(A.first);
    cout << B.second;
}
	


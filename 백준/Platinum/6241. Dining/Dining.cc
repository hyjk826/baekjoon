// 2022-11-16
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

#define MX 402

vi g[MX];
int capacity[MX][MX];
int flow[MX][MX];

void add(int a, int b){
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[a][b] = 1;
}


int main() {
	fastio;
    int n, f, d;
    cin >> n >> f >> d;
    for(int i{1}; i <= n; ++i){
        int a, b, c;
        cin >> a >> b;
        for(int j{0}; j < a; ++j){
            cin >> c;
            add(c, 100 + i);
        }
        for(int j{0}; j < b; ++j){
            cin >> c;
            add(200 + i, 300 + c);
        }
    }
    int source = 0;
    int sink = 401;
    for(int i{1}; i <= f; ++i){
        add(source, i);
    }    
    for(int i{1}; i <= n; ++i){
        add(100 + i, 200 + i);
    }
    for(int i{1}; i <= d; ++i){
        add(300 + i, sink);
    }
    int ans{0};
    while(1){
        vi par(MX, -1);
        queue<int> Q;
        Q.push(source);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            if(x == sink) break;
            for(auto& i : g[x]){
                if(capacity[x][i] - flow[x][i] > 0 && par[i] == -1){
                    par[i] = x;
                    Q.push(i);
                }
            }
        }
        if(par[sink] == -1) break;
        int k = MAX;
        for(int i{sink}; i != source; i = par[i]){
            k = min(k, capacity[par[i]][i] - flow[par[i]][i]);
        }
        for(int i{sink}; i != source; i = par[i]){
            flow[par[i]][i] += k;
            flow[i][par[i]] -= k;
        }
        ans += k;
    }
    cout << ans;
}
	


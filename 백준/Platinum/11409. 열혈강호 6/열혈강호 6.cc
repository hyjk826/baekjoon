// 2022-11-17
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

#define MX 900

vector<vi> g(MX);
int capacity[MX][MX];
int flow[MX][MX];
int d[MX][MX];
int source = MX - 1;
int sink = MX - 2; 

pi MCMF(){
    int cost{0};
    int f{0};
    while(1){
        vi p(MX, -1);
        vi dist(MX, MAX);
        vi ch(MX);
        dist[source] = 0;
        ch[source] = 1;
        queue<int> Q;
        Q.push(source);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            ch[x] = 0;
            for(auto& i : g[x]){
                if(capacity[x][i] - flow[x][i] > 0 && dist[i] > dist[x] + d[x][i]){
                    dist[i] = dist[x] + d[x][i];
                    p[i] = x;
                    if(!ch[i]){
                        Q.push(i);
                        ch[i] = 1;
                    }
                }
            }
        }
        if(p[sink] == -1) break;
        int ff = MAX;
        for(int i{sink}; i != source; i = p[i]){
            ff = min(ff, capacity[p[i]][i] - flow[p[i]][i]);
        }
        for(int i{sink}; i != source; i = p[i]){
            cost += ff * d[p[i]][i];
            flow[p[i]][i] += ff;
            flow[i][p[i]] -= ff;
        }
        f += ff;
    }
    return {f, cost};
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i){
        capacity[source][i] = 1;
        g[source].push_back(i);
        g[i].push_back(source);
    }
    for(int i{1}; i <= m; ++i){
        capacity[i + 400][sink] = 1;
        g[i + 400].push_back(sink);
        g[sink].push_back(i + 400);
    }
    for(int i{1}; i <= n; ++i){
        int a, b, c;
        cin >> a;
        for(int j{0}; j < a; ++j){
            int b, c;
            cin >> b >> c;
            g[i].push_back(b + 400);
            g[b + 400].push_back(i);
            d[i][400 + b] = -c;
            d[400 + b][i] = +c;
            capacity[i][b + 400] = 1;
        }
    }
    auto k = MCMF();
    cout << k.first << "\n" << -k.second << "\n"; 
}	
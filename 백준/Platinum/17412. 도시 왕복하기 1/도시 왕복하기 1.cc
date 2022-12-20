// 2022-07-29
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

vi graph[401];
int capacity[401][401]{};
int flow[401][401]{};

int main() {
	fastio;
    int n, p;
    cin >> n >> p;
    for(int i{0}; i < p; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        capacity[a][b] += 1;
    }
    int source = 1;
    int sink = 2;
    int ans{0};
    while(1){
        vi par(n + 1, -1);
        queue<int> Q;
        Q.push(source);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            if(x == sink) break;
            for(auto& i : graph[x]){
                if(capacity[x][i] - flow[x][i] > 0 && par[i] == -1){
                    par[i] = x;
                    Q.push(i);
                }
            }
        }
        if(par[sink] == -1) break;
        int k{MAX};
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


// 2022-06-26
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[52];
int capacity[52][52]{};
int flow[52][52]{};

int main(){
    fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        char a, b;
        int c;
        cin >> a >> b >> c;
        int x, y;
        if(a >= 'a' && a <= 'z') x = a - 'a' + 26;
        else x = a - 'A';
        if(b >= 'a' && b <= 'z') y = b - 'a' + 26;
        else y = b - 'A';
        graph[x].push_back(y);
        graph[y].push_back(x);
        capacity[x][y] += c;
        capacity[y][x] += c;
    }
    int source = 0;
    int sink = 25;
    int ans{0};
    while(1){
        vi par(52, -1);
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

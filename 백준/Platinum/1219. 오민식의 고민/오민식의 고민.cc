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

struct st{
    int a, b, c;
};

int main(){
	fastio;
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    }
    vl money(n);
    for(int i{0}; i < n; ++i){
        cin >> money[i];
    }
    vl dist(n, -LLONG_MAX);
    dist[a] = money[a];
    bool cycle = false;
    for(int i{0}; i < n - 1; ++i){
        for(int j{0}; j < m; ++j){
            if(dist[edge[j].a] == -LLONG_MAX) continue;
            ll k = -edge[j].c + money[edge[j].b];
            if(dist[edge[j].b] < dist[edge[j].a] + k){
                dist[edge[j].b] = dist[edge[j].a] + k;
            }
        }
    }
    if(dist[b] == -LLONG_MAX) cout << "gg";
    else {
        for(auto& i : edge){
            if(dist[i.a] != -LLONG_MAX && dist[i.b] < dist[i.a] + money[i.b] - i.c){
                vi ch(n);
                queue<int> Q;
                Q.push(i.a);
                while(!Q.empty()){
                    int x{Q.front()};
                    Q.pop();
                    for(auto& j : edge){
                        if(j.a == x){
                            if(ch[j.b] == 0){
                                ch[j.b] = 1;
                                Q.push(j.b);
                            }
                        }
                    }
                }
                if(ch[b]){
                    cout << "Gee"; return 0;
                }
            }
        }
        cout << dist[b];
    }
}

// 2022-05-29
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

vi graph[200000];

int main(){
    fastio;
    int n;
    cin >> n;
    vi color(n);
    for(int i{0}; i < n; ++i) cin >> color[i];
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi ch(n);
    queue<pi> Q;
    Q.push({0, color[0]});
    ch[0] = 1;
    int ans{0};
    if(color[0] != 0) ans++;
    while(!Q.empty()){
        int x{Q.front().first};
        int c{Q.front().second};
        Q.pop();
        for(auto& i : graph[x]){
            if(ch[i] == 0){
                if(c != color[i]) ans++;
                Q.push({i, color[i]});
                ch[i] = 1;
            }
        }
    }
    cout << ans;
}
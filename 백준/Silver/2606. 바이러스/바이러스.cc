// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi ch(n + 1);
    queue<int> Q;
    Q.push(1);
    ch[1] = 1;
    int ans{0};
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        ans++;
        for(auto& i : g[x]){
            if(ch[i] == 0){
                ch[i] = 1;
                Q.push(i);
            }
        }
    }
    cout << ans - 1;
}
// 2022-09-13
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

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    queue<int> Q;
    vi ch(n + 1);
    int a, b;
    cin >> a;
    for(int i{0}; i < a; ++i){
        cin >> b;
        Q.push(b);
        ch[b] = 1;
    }
    vector<vi> gg(m);
    for(int i{0}; i < m; ++i){
        cin >> a;
        for(int j{0}; j < a; ++j){
            cin >> b;
            gg[i].push_back(b);
            g[gg[i][0]].push_back(b);
            g[b].push_back(gg[i][0]);
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(ch[i] == 0){
                ch[i] = 1;
                Q.push(i);
            }
        }
    }
    int ans{0};
    for(int i{0}; i < m; ++i){
        bool flag = true;
        for(auto& j : gg[i]){
            if(ch[j]) flag = false;
        }
        if(flag) ans++;
    }
    cout << ans;
}
	


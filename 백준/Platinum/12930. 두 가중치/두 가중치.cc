// 2022-11-14
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
    int v, a, b;
    bool operator< (const st& x) const{
        return b > x.b;
    }
};



int main() {
	fastio;
    int n;
    cin >> n;
    vector<vp> g1(n);
    vector<vp> g2(n);
    for(int j{0}; j < n; ++j){
        for(int k{0}; k < n; ++k){
            char c;
            cin >> c;
            if(c == '.') continue;
            int a = c - '0';
            g1[j].push_back({k, a});
        }
    }
    for(int j{0}; j < n; ++j){
        for(int k{0}; k < n; ++k){
            char c;
            cin >> c;
            if(c == '.') continue;
            int a = c - '0';
            g2[j].push_back({k, a});
        }
    }
    for(int i{0}; i < n; ++i){
        sort(g1[i].begin(), g1[i].end());
        sort(g2[i].begin(), g2[i].end());
    }
    vector<vi> dijk(n, vi(181, MAX));
    dijk[0][0] = 0;
    priority_queue<st> pQ;
    pQ.push({0, 0, 0});
    vi ch(n, MAX);
    while(!pQ.empty()){
        int v{pQ.top().v};
        int a{pQ.top().a};
        int b{pQ.top().b};
        pQ.pop();
        if(dijk[v][a] < b) continue;
        if(ch[v] < b) continue;
        ch[v] = b;
        for(int i{0}; i < (int)g1[v].size(); i++){
            int nv{g1[v][i].first};
            if(dijk[nv][a + g1[v][i].second] > b + g2[v][i].second){
                dijk[nv][a + g1[v][i].second] = b + g2[v][i].second;
                pQ.push({nv, a + g1[v][i].second, b + g2[v][i].second});
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i <= 180; ++i){
        if(dijk[1][i] == MAX) continue;
        ans = min(ans, i * dijk[1][i]);
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	


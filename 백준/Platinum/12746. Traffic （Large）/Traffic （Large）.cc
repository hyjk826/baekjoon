// 2022-12-24
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

const int sz = 222222 + 10;
int n, q;

int imos[sz];

int sub[sz], depth[sz], par[sz], top[sz], in[sz];

vector<vi> tempg(sz);
vector<vi> g(sz);

void dfs0(int cur = 1, int pre = -1){
    for(auto& i : tempg[cur]){
        if(i == pre) continue;
        g[cur].push_back(i);
        dfs0(i, cur);
    }
}

void dfs1(int cur = 1){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        depth[i] = depth[cur] + 1;
        par[i] = cur;
        dfs1(i);
        sub[cur] += sub[i];
        if(sub[i] > sub[g[cur][0]]) swap(i, g[cur][0]);
    }
}

int pv{0};

void dfs2(int cur = 1){
    in[cur] = ++pv;
    for(auto& i : g[cur]){
        if(i == g[cur][0]){
            top[i] = top[cur];
        }
        else top[i] = i;
        dfs2(i);
    }
}

void update(int a, int b){
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        imos[in[st]]++;
        imos[in[a] + 1]--;
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    imos[in[a] + 1]++;
    imos[in[b] + 1]--;
}


int main(){
	fastio;
    cin >> n >> q;
    for(int i{1}; i <= n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    top[1] = 1;
    dfs0(1, -1);
    dfs1(1);
    dfs2(1);
    while(q--){
        int a, b;
        cin >> a >> b;
        update(a, b);
    }
    int mx{0};
    pi ans;
    for(int i{1}; i <= n; ++i){
        imos[i] += imos[i - 1];
    }
    for(int i{1}; i <= n; ++i){
        int k = imos[in[i]];
        if(k > mx){
            mx = k;
            ans = {min(i, par[i]), max(i, par[i])};
        }
        else if(k == mx){
            ans = min(ans, {min(i, par[i]), max(i, par[i])});
        }
    }
    cout << ans.first << " " << ans.second << " " << mx;
}

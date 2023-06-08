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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int n;
const int sz = (int)1e5 + 10;
vector<vi> g(sz);
vi sub(sz);
vi ch(sz);
vi color(sz);

int getSub(int cur, int pre){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        getSub(i, cur);
        sub[cur] += sub[i];
    }
    return sub[cur];
}

int getCent(int cur, int pre, int s){
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        if(sub[i] * 2 > s){
            return getCent(i, cur, s);
        }
    }
    return cur;
}

map<int, int> mp;
map<int, int> temp;
int ans{MAX};

void dfs(int L, int cur, int pre = -1){
    if(temp.count(color[cur])) temp[color[cur]] = min(temp[color[cur]], L);
    else temp[color[cur]] = L;
    if(mp.count(color[cur])) ans = min(ans, L + mp[color[cur]]);
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        dfs(L + 1, i, cur);
    }
}

void buildCentroidTree(int cur){
    int cent = getCent(cur, -1, getSub(cur, -1));
    ch[cent] = 1;
    mp.clear();
    mp[color[cent]] = 0;
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        temp.clear();
        dfs(1, i);
        for(auto& j : temp){
            if(mp.count(j.first)) mp[j.first] = min(mp[j.first], j.second);
            else mp[j.first] = j.second;
        }
    }
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        buildCentroidTree(i);
    }
}

int main(){
	fastio;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> color[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    buildCentroidTree(1);
    cout << ans;
}

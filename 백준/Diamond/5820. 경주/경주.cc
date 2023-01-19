// 2023-01-20
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

int n, k;
const int sz = (int)2e5;
vector<vp> g(sz);
vi sub(sz);
vi ch(sz);
vi A((int)1e6 + 1, MAX);

int getSub(int cur, int pre){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        if(i.first == pre || ch[i.first]) continue;
        getSub(i.first, cur);
        sub[cur] += sub[i.first];
    }
    return sub[cur];
}

int getCent(int cur, int pre, int s){
    for(auto& i : g[cur]){
        if(i.first == pre || ch[i.first]) continue;
        if(sub[i.first] * 2 > s){
            getCent(i.first, cur, s);
        }
    }
    return cur;
}

vp path;

void dfs(int L, int cur, int pre, int len){
    if(len > k) return;
    path.push_back({len, L});
    for(auto& i : g[cur]){
        if(i.first == pre || ch[i.first]) continue;
        dfs(L + 1, i.first, cur, len + i.second);
    }
}

int ans{MAX};

void cdn(int cur){
    int cent = getCent(cur, -1, getSub(cur, -1));
    vi R;
    for(auto& i : g[cent]){
        if(ch[i.first]) continue;
        path.clear();
        dfs(1, i.first, cent, i.second);
        for(auto& j : path){
            ans = min(ans, A[k - j.first] + j.second);
        }
        for(auto& j : path){
            if(j.second < A[j.first]){
                A[j.first] = j.second;
                R.push_back(j.first);
            }
        }
    }
    for(auto& i : R) A[i] = MAX;
    ch[cent] = 1;
    for(auto& i : g[cent]){
        if(ch[i.first]) continue;
        cdn(i.first);
    }
}

int main(){
	fastio;
    cin >> n >> k;
    A[0] = 0;
    for(int i{0}; i < n - 1; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    cdn(0);
    if(ans == MAX) cout << -1;
    else cout << ans;
}

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
#define MOD 998244353
using namespace std;

int n;
const int sz = (int)3e5 + 1;
vector<vi> g(sz);
int sub[sz];
int ch[sz];

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

ll ans{0};
int ch1[sz];
int ch2[sz];
ll sqa, sqb, suma, sumb, cnta, cntb;
ll tsqa, tsqb, tsuma, tsumb, tcnta, tcntb;
vp path;

void dfs(int L, int cur, int pre){
    if(ch1[cur]) path.push_back({L, 1});
    if(ch2[cur]) path.push_back({L, 2});
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        dfs(L + 1, i, cur);
    }
}


void cdn(int cur){
    int cent = getCent(cur, -1, getSub(cur, -1));
    sqa = sqb = suma = sumb = cnta = cntb = 0;
    if(ch1[cent]) {
        cnta++;
    }
    if(ch2[cent]) {
        cntb++;
    }
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        path.clear();
        tsqa = tsqb = tsuma = tsumb = tcnta = tcntb = 0;
        dfs(1, i, cent);
        for(auto& j : path){
            if(j.second == 1){
                tsqa += 1LL * j.first * j.first; tsqa %= MOD;
                tsuma += j.first; tsuma %= MOD;
                tcnta++;
            }
            else{
                tsqb += 1LL * j.first * j.first; tsqb %= MOD;
                tsumb += j.first; tsumb %= MOD;
                tcntb++;
            }
        }
        ans += cntb * tsqa; ans %= MOD;
        ans += tcnta * sqb; ans %= MOD;
        ans += 2 * suma * tsumb; ans %= MOD;
        ans += cnta * tsqb; ans %= MOD;
        ans += tcntb * sqa; ans %= MOD;
        ans += 2 * sumb * tsuma; ans %= MOD;
        for(auto& j : path){
            if(j.second == 1){
                sqa += 1LL * j.first * j.first; sqa %= MOD;
                suma += j.first; suma %= MOD;
                cnta++;
            }
            else{
                sqb += 1LL * j.first * j.first; sqb %= MOD;
                sumb += j.first; sumb %= MOD;
                cntb++;
            }
        }
    }
    ch[cent] = 1;
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        cdn(i);
    }
}

int main(){
	fastio;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int a, b;
    cin >> a;
    for(int i{0}; i < a; ++i){
        int x;
        cin >> x;
        ch1[x]++;
    }
    cin >> b;
    for(int i{0}; i < b; ++i){
        int x;
        cin >> x;
        ch2[x]++;
    }
    cdn(1);
    cout << ans;
}

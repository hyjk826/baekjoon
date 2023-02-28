// 2022-12-31
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

int n;
string str;
const int sz = (int)2e5 + 1;
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
map<int, map<int,int>> mp;
map<int, map<int,int>> mp2;

void dfs(int cur, int pre, int u, int p, int c){
    mp2[u - p][u + p - c]++;
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        dfs(i, cur, u + (str[i] == 'U'), p + (str[i] == 'P'), c + (str[i] == 'C'));
    }
}


void cdn(int cur){
    int cent = getCent(cur, -1, getSub(cur, -1));
    mp.clear();
    mp[0][0]++;
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        mp2.clear();
        dfs(i, cent, (str[i] == 'U'), (str[i] == 'P'), (str[i] == 'C'));
        for(auto& j : mp2){
            for(auto& k : j.second){
                int a = j.first;
                int b = k.first;
                if(str[cent] == 'U') a++, b++;
                else if(str[cent] == 'P') a--, b++;
                else if(str[cent] == 'C') b--;
                if(mp.count(-a) && mp[-a].count(-b)) ans += 1LL * k.second * mp[-a][-b];
            }
        }
        for(auto& j : mp2){
            for(auto& k : j.second){
                mp[j.first][k.first] += k.second;
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
    cin >> n >> str;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cdn(0);
    cout << ans;
}

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

vi p(1e5 + 1);

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> game(m + 1);
    vi cnt(m + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        cnt[a]++;
        game[a].push_back(i);
    }
    vp edge(q);
    for(int i{0}; i < q; ++i){
        cin >> edge[i].first >> edge[i].second;
    }
    vi l(m + 1), r(m + 1, q - 1);
    vi ans(m + 1, -1);
    while(1){
        bool ok = false;
        vector<vi> mid(q);
        for(int i{1}; i <= m; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{1}; i <= n; ++i){
            p[i] = i;
        }
        for(int i{0}; i < q; ++i){
            merge(edge[i].first, edge[i].second);
            for(auto& j : mid[i]){
                bool ok2 = true;
                for(int a{0}; a < game[j].size(); ++a){
                    if(find(game[j][a]) != find(game[j][0])){
                        ok2 = false;
                        break;
                    }
                }
                if(ok2){
                    ans[j] = i + 1;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
    }
    for(int i{1}; i <= m; ++i){
        if(cnt[i] == 1) cout << 0 << "\n";
        else cout << ans[i] << "\n";
    }
}

// 2023-01-06
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

const int sz = (int)1e5 + 1;

vi uni(sz);
vi cnt(sz);

struct st{
    int a, b, w;
};

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        cnt[b] += cnt[a];
        cnt[a] = 0;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w < y.w;
    });
    int q;
    cin >> q;
    vp query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].first >> query[i].second;
    }
    vi l(m), r(m, m - 1);
    vp ans(q);
    while(1){
        bool ok = false;
        vector<vi> mid(sz);
        for(int i{0}; i < q; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) / 2].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{1}; i <= n; ++i){
            uni[i] = i;
            cnt[i] = 1;
        }
        for(int i{0}; i < m; ++i){
            Union(edge[i].a, edge[i].b);
            for(auto& j : mid[i]){
                int a = find(query[j].first);
                int b = find(query[j].second);
                if(a == b){
                    r[j] = i - 1;
                    ans[j].first = edge[i].w;
                    ans[j].second = cnt[a];
                }
                else l[j] = i + 1;
            }
        }
    }
    for(auto& i : ans){
        if(i.first == 0) cout << -1 << "\n";
        else cout << i.first << " " << i.second << "\n";
    }
}

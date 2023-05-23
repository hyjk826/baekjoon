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

int p[2001];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b; return 1;
    }
    return 0;
}

struct st{
    int u, v, w;
};

int main(){
	fastio;
	int n, m, s;
    cin >> n >> m >> s;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }  
    sort(edge.begin(), edge.end(), [&](st& x, st& y){
        return x.w < y.w;
    });
    iota(p, p + n + 1, 0);
    int ans{0};
    for(auto& i : edge){
        if(merge(i.u, i.v)){
            ans += i.w;
        }
    }
    cout << ans;
}

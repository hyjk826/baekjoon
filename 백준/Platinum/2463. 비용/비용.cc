// 2022-12-11
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
#define MOD 1000000000
using namespace std;

struct st{
    int a, b, w;
};

vi uni(100001);
vi cnt(100001);


int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
        cnt[i] = 1;
    }
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w > y.w;
    });
    vl vec(m);
    vec[0] = edge.back().w;
    for(int i{1}; i < m; ++i){
        vec[i] += vec[i - 1] + edge[m - i - 1].w;
    }
    ll ans{0};
    for(int i{0}; i < m; ++i){
        int a = edge[i].a;
        int b = edge[i].b;
        a = find(a);
        b = find(b);
        if(a != b) {
            ans += 1LL * cnt[a] * cnt[b] * vec[m - i - 1];
            ans %= MOD;
            cnt[b] += cnt[a];
            cnt[a] = 0;
            uni[a] = b;      
        }
    }
    cout << ans;
}
	

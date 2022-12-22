// 2022-12-23
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
    int a, b;
    ll w;
};

vi uni(2001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

int main(){
	int n, m;
    cin >> n >> m;
    vector<st> edge(m);
    ll k{1};
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b;
        edge[i].w = k;
        k = (k * 3) % MOD;
    }
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    int ans{0};
    for(int i{m - 1}; i >= 0; --i){
        int a = find(0);
        int b = find(n - 1);
        int x = find(edge[i].a);
        int y = find(edge[i].b);
        if(tie(a, b) == tie(x, y) || tie(a, b) == tie(y, x)){
            ans += edge[i].w;
            ans %= MOD;
        }
        else uni[x] = y;
    }
    cout << ans;
}

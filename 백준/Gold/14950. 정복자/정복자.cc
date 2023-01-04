// 2023-01-04
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

int main(){
	fastio;
    int n, m, t;
    cin >> n >> m >> t;
    vi uni(n + 1);
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    struct st{
        int a, b, w;
    };
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w < y.w;
    });
    ll ans{0};
    function<int(int)> find = [&](int a){
        if(a == uni[a]) return a;
        return uni[a] = find(uni[a]);
    };
    function<bool(int, int)> Union = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            uni[a] = b;
            return true;
        }
        return false;
    };
    for(auto& i : edge){
        if(Union(i.a, i.b)){
            ans += i.w;
        }
    }
    ans += 1LL * (n - 1) * (n - 2) / 2 * t;
    cout << ans;
}

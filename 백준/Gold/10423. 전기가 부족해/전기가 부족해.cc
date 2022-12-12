// 2022-12-12
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
    int a, b, w;
};

vi uni(1001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return 1;
    }
    return 0;
}


int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vi A(k);
    for(int i{1}; i <= n; ++i) uni[i] = i;
    for(int i{0}; i < k; ++i){
        cin >> A[i];
    }
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w < y.w;
    });
    for(int i{0}; i < k - 1; ++i){
        Union(A[i], A[i + 1]);
    }
    ll ans{0};
    for(int i{0}; i < m; ++i){
        if(Union(edge[i].a, edge[i].b)) ans += edge[i].w;
    }
    cout << ans << "\n";
}
	

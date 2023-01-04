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

vi uni(100001);

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

struct st{
    int a, b, w;
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }  
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w > y.w;
    });
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    for(auto& i : edge){
        Union(i.a, i.b);
        int a = find(s);
        int b = find(t);
        if(a == b){
            cout << i.w;
            return 0;
        }
    }
    cout << 0;
}

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

struct E{
    int u, v, w;
};

int p[1000];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    function<int(int,int,int,int)> f = [&](int a, int b, int c, int d){
        return (b + d) / abs(a - c);
    };
    vector<E> edge;
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            edge.push_back({i, j, f(vec[i].first, vec[i].second, vec[j].first, vec[j].second)});
        }
    }
    sort(edge.begin(), edge.end(), [&](E& x, E& y){
        return x.w > y.w;
    });
    for(int i{0}; i < n; ++i) {
        p[i] = i;
    }
    vector<vi> g(n);
    ll ans{0};
    vi degree(n);
    for(auto& i : edge){
        if(Union(i.u, i.v)){
            g[i.u].push_back(i.v);
            g[i.v].push_back(i.u);
            ans += i.w;
        }
    }
    queue<int> Q;
    Q.push(0);
    vi par(n, -1);
    par[0] = 0;
    vi path;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        path.push_back(x);
        for(auto& i : g[x]){
            if(par[i] == -1){
                par[i] = x;
                Q.push(i);
            }
        }
    }
    reverse(path.begin(), path.end());
    cout << ans << "\n";
    path.pop_back();
    for(auto& i : path){
        cout << par[i] + 1 << " " << i + 1 << "\n";
    }
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

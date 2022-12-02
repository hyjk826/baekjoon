// 2022-11-20
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
    int v, s;
    ll a, b;
    bool operator< (const st& x) const{
        return a * x.b > x.a * b;
    }
};

struct st2{
    int a, b, c;
};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a ,ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

bool f(pl a, pl b){
    return a.first * b.second < b.first * a.second;
}

pl f2(pl a, pl b){
    ll k = lcm(a.second, b.second);
    return {a.first * (k / a.second) + b.first * (k / b.second), k};
}



int main() {
	fastio;	
    int n, m;
    cin >> n >> m;
    vector<vector<st2>> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }
    cout << fixed << setprecision(9);
    vector<vector<pl> > dijk(n + 1, vector<pl>(11, {(ll)1e15, 1}));
    dijk[1][1] = {0, 1};
    priority_queue<st> pQ;
    pQ.push({1, 1, 0, 1});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int s{pQ.top().s};
        ll a{pQ.top().a};
        ll b{pQ.top().b};
        pQ.pop();
        if(f(dijk[v][s], {a, b})) continue;
        for(auto& i : g[v]){
            int nv{i.a};
            for(int j{-1}; j <= 1; ++j){
                int ns{s + j};
                if(ns == 0 || ns == 11) continue;
                if(ns <= i.c){
                    pl k = f2({a, b}, {i.b, ns});
                    if(f(k, dijk[nv][ns])){
                        dijk[nv][ns] = k;
                        pQ.push({nv, ns, k.first, k.second});
                    }
                }
            }
        }
    }
    pl ans = {(ll)1e15, 1};
    for(int i{0}; i <= 10; ++i){
        if(f(dijk[n][i], ans)){
            ans = dijk[n][i];
        }
    }
    long double r = 1.0;
    r *= ans.first;
    r /= ans.second;
    cout << r << "\n";
}
	


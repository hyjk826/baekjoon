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
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> Q;
    vi P(n + 1);
    Q.push(1);
    P[1] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(P[i] == 0){
                P[i] = x;
                Q.push(i);
            }
        }
    }
    int q;
    cin >> q;
    vi ch(n + 1, -1);
    while(q--){
        int m;
        cin >> m;
        vi vec(m);
        for(int i{0}; i < m; ++i){
            cin >> vec[i];
            ch[vec[i]] = i;
        }
        vi p(m);
        vi cnt(m, 1);
        for(int i{0}; i < m; ++i){
            p[i] = i;
        }
        function<int(int)> find = [&](int a){
            if(p[a] == a) return a;
            return p[a] = find(p[a]);
        };
        function<bool(int,int)> merge = [&](int a, int b){
            a = find(a);
            b = find(b);
            if(a != b){
                p[a] = b;
                cnt[b] += cnt[a];
                cnt[a] = 0;
                return true;
            }
            return false;
        };
        for(int i{0}; i < m; ++i){
            if(ch[P[vec[i]]] != -1) merge(i, ch[P[vec[i]]]);
        }
        ll ans{0};
        for(int i{0}; i < m; ++i){
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans << "\n";
        for(int i{0}; i < m; ++i){
            ch[vec[i]] = -1;
        }
    }
}

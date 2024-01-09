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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n, m;
    cin >> n >> m;
    vi p(n);
    function<int(int)> find = [&](int a){
        if(a == p[a]) return a;
        return p[a] = find(p[a]);
    };
    function<bool(int,int)> merge = [&](int a, int b){
        a = find(a); b = find(b);
        if(a ^ b){
            p[a] = b;
            return true;
        }
        return false;
    };
    iota(p.begin(), p.end(), 0);
    vector<vi> g(n);
    vp A;
    for(int i{0}; i < m; ++i){
        int a, b;
        char c;
        cin >> a >> c >> b;
        if(c == '=') merge(a, b);
        else if(c == '>') A.push_back({a, b});
    }
    vi degree(n);
    for(auto& i : A){
        int a = find(i.first); int b = find(i.second);
        if(a == b){
            cout << "inconsistent\n"; return;
        }
        g[a].push_back(b);
        degree[b]++;
    }
    int cnt{0};
    int cnt2{0};
    queue<int> Q;
    for(int i{0}; i < n; ++i){
        if(i == find(i)){
            cnt++;
            if(degree[i] == 0) {
                Q.push(i);
            }
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        cnt2++;
        for(auto& i : g[x]){
            degree[i]--;
            if(degree[i] == 0){
                Q.push(i);
            }
        }
    }
    if(cnt2 == cnt) cout << "consistent\n";
    else cout << "inconsistent\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

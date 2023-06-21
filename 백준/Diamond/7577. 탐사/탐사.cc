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
    int u, v, w;
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<st> edge;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a - 1, b, c});
        edge.push_back({b, a - 1, -c});
    }
    for(int i{1}; i <= n; ++i){
        edge.push_back({i - 1, i, 1});
        edge.push_back({i, i - 1, 0});
        edge.push_back({n + 1, i, 0});
    }
    edge.push_back({n + 1, 0, 0});
    vi bell(n + 2, (int)1e9);
    bell[n + 1] = 0;
    for(int i{0}; i < n - 1; ++i){
        for(auto& i : edge){
            int a = i.u;
            int b = i.v;
            int c = i.w;
            if(bell[b] > bell[a] + c){
                bell[b] = bell[a] + c;
            }
        }
    }
    bool ok = true;
    for(auto& i : edge){
        if(bell[i.v] > bell[i.u] + i.w) ok = false;
    }
    if(ok){
        for(int i{1}; i <= n; ++i){
            if(bell[i] == bell[i - 1]) cout << "-";
            else cout << "#";
        }
    }
    else cout << "NONE\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

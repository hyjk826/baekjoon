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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<E> edge(m);
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vp ch(n + 1, {-2, -2});
    function<void(int)> dfs = [&](int cur){
        for(auto& i : g[cur]){
            if(ch[i.first].first == -2){
                ch[i.first] = {-ch[cur].first, i.second - ch[cur].second};
                dfs(i.first);
            }
        }
    };
    ch[1] = {1, 0};
    dfs(1);
    vi A;
    vi B;
    bool ok = true;
    for(auto& i : edge){
        int a = i.u;
        int b = i.v;
        int w = i.w;
        if(ch[a].first == ch[b].first){
            int k = ch[a].second + ch[b].second;
            if((w - k) & 1) ok = false;
            else{
                if(ch[a].first == -1) B.push_back(-(w - k) / 2);
                else B.push_back((w - k) / 2);
            }
        }
        else{
            ok &= (w == ch[a].second + ch[b].second);
        }
    }
    for(int i{1}; i <= n; ++i){
        A.push_back(ch[i].first * ch[i].second * -1);
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    if(!ok || B.size() >= 2){
        cout << "No"; return;
    }
    else if(B.size() == 1){
        cout << "Yes\n";
        for(int i{1}; i <= n; ++i){
            cout << B[0] * ch[i].first + ch[i].second << " ";
        }
    }
    else{
        sort(A.begin(), A.end());
        int k = A[(int)A.size() / 2];
        cout << "Yes\n";
        for(int i{1}; i <= n; ++i){
            cout << k * ch[i].first + ch[i].second << " ";
        }
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

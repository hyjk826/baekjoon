// 2022-09-19
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    vector<vi> floyd(n, vi(n, (int)1e8));
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        floyd[a][b] = 1;
        floyd[b][a] = 1;
    }
    for(int i{0}; i < n; ++i){
        floyd[i][i] = 0;
    }
    for(int k{0}; k < n; ++k){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    vi ch(n, -1);
    int k{0};
    for(int i{0}; i < n; ++i){
        if(ch[i] == -1){
            ch[i] = k;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& j : g[x]){
                    if(ch[j] == -1){
                        ch[j] = k;
                        Q.push(j);
                    }
                }
            }
            k++;
        }
    }
    vi ch2(k, MAX);
    vi ans(k);
    for(int i{0}; i < n; ++i){
        int mx{0};
        for(int j{0}; j < n; ++j){
            if(floyd[i][j] == (int)1e8) continue;
            mx = max(mx, floyd[i][j]);
        }
        if(ch2[ch[i]] > mx){
            ch2[ch[i]] = mx;
            ans[ch[i]] = i;
        }
    }
    cout << k << "\n";
    sort(ans.begin(), ans.end());
    for(auto& i : ans){
        cout << i + 1 << "\n";
    }
}
	


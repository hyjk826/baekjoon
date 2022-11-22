// 2022-11-21
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

int main() {
	fastio;	
    int n;
    cin >> n;
    vector<vp> g(n + 1);
    map<pi, int> mp;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
        mp[{a, b}] = i;
        mp[{b, a}] = i;
    }
    queue<int> Q;
    Q.push(1);
    vi dist(n + 1, -1);
    vi cnt(n + 1, -1);
    dist[1] = 0;
    cnt[1] = 0;
    int k{0};
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dist[i.first] == -1){
                if(i.second == 1) k++;
                cnt[i.first] = cnt[x] + i.second;
                dist[i.first] = dist[x] + 1;
                Q.push(i.first);
            }
        }
    }
    vi A(n + 1);
    A[1] = k;
    int mn{1};
    vi ans(n - 1);
    for(int i{2}; i <= n; ++i){
        A[i] = k + dist[i] - cnt[i] - cnt[i];
        if(A[i] < A[mn]){
            mn = i;
        }
    }
    Q.push(mn);
    vi ch(n + 1);
    ch[mn] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(ch[i.first] == 0){
                ch[i.first] = 1;
                if(i.second == 1){
                    ans[mp[{i.first, x}]] = 1;
                }
                Q.push(i.first);
            }
        }
    }
    for(auto& i : ans) cout << i;
}
	


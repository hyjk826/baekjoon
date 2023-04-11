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
    for(int i{0}; i <= n; ++i){
        for(int j{0}; j < 20; ++j){
            int k = i ^ (1 << j);
            if(k <= n) {
                g[i].push_back(k);
            }
        }
    }
    int m;
    cin >> m;
    queue<int> Q;
    vi dist(n + 1, -1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        Q.push(a);
        dist[a] = 0;
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dist[i] == -1){
                dist[i] = dist[x] + 1;
                Q.push(i);
            }
        }
    }
    cout << *max_element(dist.begin(), dist.end());
}

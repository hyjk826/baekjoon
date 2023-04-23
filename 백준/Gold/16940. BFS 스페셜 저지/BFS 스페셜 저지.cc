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
    vector<set<int>> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    vi path(n);
    for(int i{0}; i < n; ++i){
        cin >> path[i];
    }
    queue<int> Q;
    Q.push(path[0]);
    int idx{1};
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        while(idx < n && g[x].count(path[idx])){
            Q.push(path[idx]);
            idx++;
        }
    }
    if(path[0] == 1 && idx == n) cout << 1;
    else cout << 0;
}

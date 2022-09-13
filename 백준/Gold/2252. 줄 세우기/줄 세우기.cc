// 2022-09-14
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
    vi indegree(n + 1);
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }
    queue<int> Q;
    for(int i{1}; i <= n; ++i){
        if(indegree[i] == 0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        cout << x << " ";
        for(auto& i : g[x]){
            indegree[i]--;
            if(indegree[i] == 0){
                Q.push(i);
            }
        }
    }
}
	


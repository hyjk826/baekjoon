// 2022-12-11
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
	int n, m;
    cin >> n >> m;
    vector<vp> g(n);
    vector<vp> g2(n);
    vi indegree(n);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        g2[b].push_back({a, c});
        indegree[b]++;
    }
    vi A(n);
    int s, e;
    cin >> s >> e;
    s--; e--;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            indegree[i.first]--;
            A[i.first] = max(A[i.first], A[x] + i.second);
            if(indegree[i.first] == 0){
                Q.push(i.first);
            }
        }
    }
    int cnt{0};
    Q.push(e);
    set<pi> st;
    vi ch(n);
    ch[e] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g2[x]){
            if(A[i.first] + i.second == A[x]){
                cnt++;
                if(ch[i.first] == 0){
                    ch[i.first] = 1;
                    Q.push(i.first);
                }
            }            
        }
    }
    cout << A[e] << "\n" << cnt;
}
	

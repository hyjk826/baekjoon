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
    vi degree(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    int a, b, c;
    cin >> a >> b >> c;
    function<vi(int)> f = [&](int s){
        queue<int> Q;
        vi dist(n + 1, -1);
        Q.push(s);
        dist[s] = 0;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& i : g[x]){
                if(dist[i] == -1){
                    dist[i]= dist[x] + 1;
                    Q.push(i);
                }
            }
        }
        return dist;
    };
    vi A = f(a);
    vi B = f(b);
    vi C = f(c);
    bool ok = false;
    for(int i{1}; i <= n; ++i){
        if(degree[i] > 1) continue;
        if(A[i] < B[i] && A[i] < C[i]){
            ok = true; break;
        }
    }
    if(ok) cout << "YES";
    else cout << "NO";
}

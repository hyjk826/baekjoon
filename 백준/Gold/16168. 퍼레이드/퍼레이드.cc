// 2022-12-15
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
    vector<vi> g(n);
    vi degree(n);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        degree[a]++;
        degree[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi ch(n);
    int c{0};
    for(int i{0}; i < n; ++i){
        if(ch[i] == 0){
            int cnt{0};
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int v{Q.front()};
                Q.pop();
                cnt++;
                for(auto& i : g[v]){
                    if(ch[i] == 0){
                        ch[i] = 1;
                        Q.push(i);
                    }
                }
            }
            c++;
        }
    }
    int a, b;
    a = b = 0;
    for(int i{0}; i < n; ++i){
        if(degree[i] & 1) a++;
        else b++;
    }
    if(c == 1 && a <= 2) cout << "YES";
    else cout << "NO";
}
	

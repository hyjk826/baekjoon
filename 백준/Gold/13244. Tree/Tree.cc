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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vi> g(n + 1);
        for(int i{0}; i < m; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if(m == n - 1){
            vi ch(n + 1);
            queue<int> Q;
            Q.push(1);
            ch[1] = 1;
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& i : g[x]){
                    if(ch[i] == 0){
                        ch[i] = 1;
                        Q.push(i);
                    }
                }
            }
            if(accumulate(ch.begin(), ch.end(), 0) == n) cout << "tree\n";
            else cout << "graph\n";
        }
        else cout << "graph\n";
    }
}

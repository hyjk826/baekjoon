// 2022-11-24
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
    vector<vi> g(n + 1);
    for(int i{2}; i <= n; ++i){
        int a;
        cin >> a;
        g[a].push_back(i);
    }
    vi ch(n + 1);
    ch[1] = 1;
    vi A(n + 1, 1);
    ll ans{0};
    for(int i{0}; i < m; ++i){
        char c; int a;
        cin >> c >> a;
        if(c == 'Q'){
            ans += A[a];
        }
        else{
            queue<int> Q;
            if(ch[a]) continue;
            ch[a] = 1;
            A[a] = a;
            Q.push(a);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& i : g[x]){
                    if(ch[i] == 0){            
                        A[i] = a;
                        Q.push(i);
                    }
                }
            }
        }
    }
    cout << ans;
}
	

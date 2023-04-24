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
    int n, k, m;
    cin >> n >> k >> m;
    vector<vi> g(n + m + 1);
    for(int i{0}; i < m; ++i){
        for(int j{0}; j < k; ++j){
            int a;
            cin >> a;
            g[a].push_back(i + n + 1);
            g[i + n + 1].push_back(a);
        }
    }
    deque<int> Q;
    Q.push_back(1);
    vi ch(n + m + 1);
    ch[1] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop_front();
        for(auto& i : g[x]){
            if(ch[i] == 0){
                if(i > n){
                    Q.push_front(i);
                    ch[i] = ch[x];
                }
                else{
                    Q.push_back(i);
                    ch[i] = ch[x] + 1;
                }
            }
        }
    }
    if(ch[n] == 0) cout << -1;
    else cout << ch[n];
}

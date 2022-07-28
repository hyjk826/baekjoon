// 2022-07-28
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

vi graph[10001];

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi ch(n + 1);
    int sum{0};
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0){
            int mn{MAX};
            ch[i] = 1;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                mn = min(mn, vec[x]);
                for(auto& j : graph[x]){
                    if(ch[j] == 0){
                        ch[j] = 1;
                        Q.push(j);
                    }
                }
            }
            sum += mn;
        }
    }
    if(sum <= k) cout << sum;
    else cout << "Oh no";
}


// 2022-09-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    int mn{MAX};
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans{-1};
    for(int i{1}; i <= n; ++i){
        queue<int> Q;
        Q.push(i);
        vi ch(n + 1, -1);
        ch[i] = 0;
        int sum{0};
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            sum += ch[x];
            for(auto& i : g[x]){
                if(ch[i] == -1){
                    ch[i] = ch[x] + 1;
                    Q.push(i);
                }
            }
        }
        if(sum < mn){
            mn = sum;
            ans = i;
        }
    }
    cout << ans;
}
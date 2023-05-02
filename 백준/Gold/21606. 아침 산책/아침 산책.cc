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
    string str;
    cin >> str;
    vector<vi> g(n + 1);
    ll ans{0};
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        if(str[a - 1] == str[b - 1] && str[a - 1] == '1') ans += 2;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi ch(n + 1);
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        if(str[i - 1] == '1') continue;
        queue<int> Q;
        Q.push(i);
        ch[i] = 1;
        int cnt{0};
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& j : g[x]){
                if(str[j - 1] == '1') cnt++;
                else{
                    if(ch[j] == 0){
                        ch[j] = 1;
                        Q.push(j);
                    }
                }
            }
        }
        ans += 1LL * cnt * (cnt - 1);
    }
    cout << ans;
}

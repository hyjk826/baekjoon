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
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi cnt(n + 1);
    string str;
    cin >> str;
    vi color(n + 1);
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i]== 'B') color[i + 1] = 1;
        else color[i + 1] = 2;
    }
    vi ch(n + 1);
    queue<int> Q;
    for(int i{1}; i <= n; ++i){
        if(color[i] == 1 || ch[i]) continue;
        ch[i] = 1;
        queue<int> Q;
        Q.push(i);
        vi A;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            A.push_back(x);
            for(auto& j : g[x]){
                if(ch[j] || color[j] == 1) continue;
                ch[j] = 1;
                Q.push(j); 
            }
        }
        for(auto& j : A){
            cnt[j] = (int)A.size();
        }
    }
    ll ans{0};
    for(int i{1}; i <= n; ++i){
        if(color[i] == 1){
            for(auto& j : g[i]){
                if(color[j] == 2){
                    ans += cnt[j];
                }
            }
        }
    }
    cout << ans;
}

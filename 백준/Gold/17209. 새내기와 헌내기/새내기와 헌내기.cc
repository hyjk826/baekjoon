// 2022-12-14
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
    int n;
    cin >> n;
    vector<vi> g(n);
    vi A;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char c;
            cin >> c;
            if(c == '1'){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans{n};
    vi ch(n, -1);
    for(int i{0}; i < n; ++i){
        if(ch[i] == -1){
            ch[i] = 0;
            vi cnt(2);
            cnt[0]++;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& i : g[x]){
                    if(ch[i] == -1){
                        ch[i] = ch[x] ^ 1;
                        cnt[ch[i]]++;
                        Q.push(i);
                    }
                }
            }
            ans -= min(cnt[0], cnt[1]);
        }
    }
    cout << ans;
}
	

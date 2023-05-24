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
	int n, m, q;
    cin >> n >> m >> q;
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi ch(n + 1);
    vi component(n + 1);
    int cnt{1};
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        queue<int> Q;
        Q.push(i);
        ch[i] = cnt;
        bool ok = true;
        vi A;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            component[x] = cnt;
            A.push_back(x);
            for(auto& j : g[x]){
                if(ch[j] == 0){
                    if(ch[x] & 1) ch[j] = ch[x] + 1;
                    else ch[j] = ch[x] - 1;
                    Q.push(j);
                }
                else if(ch[j] == ch[x]){
                    ok = false;
                }
            }
        }
        if(!ok){
            for(auto& i : A) ch[i] = cnt;
        }
        cnt += 2;
    }
    while(q--){
        int a, b, k;
        cin >> a >> b >> k;
        if(k & 1){
            if(component[a] == component[b]) cout << "Yes\n";
            else cout << "No\n";
        }
        else{
            if(ch[a] == ch[b]) cout << "Yes\n";
            else cout << "No\n";
        }
    }

}

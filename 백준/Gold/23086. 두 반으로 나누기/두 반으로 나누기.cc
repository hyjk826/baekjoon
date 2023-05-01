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
    int n, m, k;
    cin >> n >> m >> k;
    vp edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].first >> edge[i].second;
    }
    vi A(k);
    vi ch(m);
    for(int i{0}; i < k; ++i){
        cin >> A[i];
        A[i]--;
        ch[A[i]] = 1;
    }
    int l{0}, r{k};
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        if(ch[i]) continue;
        int a = edge[i].first;
        int b = edge[i].second;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        vector<vi> temp = g;
        for(int i{mid}; i < k; ++i){
            int a = edge[A[i]].first;
            int b = edge[A[i]].second;
            temp[a].push_back(b);
            temp[b].push_back(a);
        }
        vi C(n + 1, -1);
        C[1] = 0;
        bool ok = true;
        queue<int> Q;
        Q.push(1);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& j : temp[x]){
                if(C[j] == -1){
                    C[j] = C[x] ^ 1;
                    Q.push(j);                    
                }
                else if(C[j] == C[x]){
                    ok = false; break;
                }
            }
        }
        if(ok){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    if(ans == -1) cout << -1;
    else{
        for(int i{ans}; i < k; ++i){
            int a = edge[A[i]].first;
            int b = edge[A[i]].second;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vi C(n + 1, -1);
        C[1] = 0;
        queue<int> Q;
        Q.push(1);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& j : g[x]){
                if(C[j] == -1){
                    C[j] = C[x] ^ 1;
                    Q.push(j);
                }
            }
        }
        int a{0}, b{0};
        for(int i{1}; i <= n; ++i){
            if(C[i] == 0) a++;
            else b++;
        }
        if(b < a) swap(a, b);
        cout << ans << "\n";
        cout << a << " " << b;
    }
}

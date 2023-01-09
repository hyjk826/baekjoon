// 2023-01-09
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
    int n, q;
    cin >> n >> q;
    vector<vi> g(n + 1);
    vi degree(n + 1);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    vi ch(n + 1);
    queue<int> Q;
    for(int i{1}; i <= n; ++i){
        if(degree[i] == 1){
            Q.push(i);
            ch[i] = 1;
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            degree[i]--;
            if(degree[i] == 1){
                Q.push(i);
                ch[i] = 1;
            }
        }
    }
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0){
            Q.push(i);
            A[i] = i;
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){            
            if(A[i] == 0){
                A[i] = A[x];
                Q.push(i);
            }
        }
    }
    for(int i{0}; i < q; ++i){
        int a, b;
        cin >> a >> b;
        if(A[a] == A[b]) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}

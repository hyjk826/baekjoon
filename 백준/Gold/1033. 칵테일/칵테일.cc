// 2022-12-30
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

struct st{
    int a, b, c, d;
};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> g(n);
    vector<st> vec(n);
    for(int i{0}; i < n - 1; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c >> vec[i].d;
        g[vec[i].a].push_back(vec[i].b);
        g[vec[i].b].push_back(vec[i].a);
    }
    vl ans(n, 1);
    for(int i{0}; i < n - 1; ++i){
        int a = vec[i].a;
        int b = vec[i].b;
        queue<int> Q;
        Q.push(a);
        vi ch(n);
        ch[a] = 1;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            ans[x] *= vec[i].c;
            for(auto& j : g[x]){
                if(ch[j] == 0 && j != b){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
        Q.push(b);
        ch[b] = 1;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            ans[x] *= vec[i].d;
            for(auto& j : g[x]){
                if(ch[j] == 0 && j != a){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    ll a = 0;
    for(int i{0}; i < n; ++i){
        a = gcd(a, ans[i]);
    }
    for(int i{0}; i < n; ++i){
        cout << ans[i] / a << " ";
    }
}

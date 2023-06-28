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

const int sz = 1000 + 10;
vector<vi> g(sz);
vi ch(sz);
vi match(sz);
int A[sz];
int B[sz];

bool bipartiteMatching(int x)
{
    for(auto& nx : g[x]){
        if (ch[nx] == 0)
        {
            ch[nx] = 1;
            if (match[nx] == 0 || bipartiteMatching(match[nx]))
            {
                match[nx] = x;
                return true;
            }
        }
    }
    return false;
}

void f(int x){
    if(ch[x]) return;
    ch[x] = 1;
    for(auto& i : g[x]){
        B[i] = 1;
        if(match[i]) f(match[i]);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        for(int j{0}; j < a; ++j){
            int b;
            cin >> b;
            g[i].push_back(b);
        }
    }
    for(int i{1}; i <= n; ++i){
        if(bipartiteMatching(i)) A[i] = 1;
        fill(ch.begin(), ch.end(), 0);
    }
    for(int i{1}; i <= n; ++i){
        if(A[i] || ch[i]) continue;
        f(i);
    }
    vi a, b;
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        a.push_back(i);
    }
    for(int i{1}; i <= m; ++i){
        if(B[i]) b.push_back(i);
    }
    cout << a.size() + b.size() << "\n";
    cout << a.size() << " ";
    for(auto& i : a) cout << i << " ";
    cout << "\n";
    cout << b.size() << " ";
    for(auto& i : b) cout << i << " ";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

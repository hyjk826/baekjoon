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

const int sz = 2000 + 10;
vector<vi> g(sz);
vector<int> ch(sz);
vector<int> match(sz, -1);

bool bipartiteMatching(int x)
{
    for(auto& nx : g[x]){
        if (ch[nx] == 0)
        {
            ch[nx] = 1;
            if (match[nx] == -1 || bipartiteMatching(match[nx]))
            {
                match[nx] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    int ans{n};
    vi cc(n + 1);
    for(int i{0}; i < n; ++i){
        int a; char c;
        cin >> a >> c;
        if(c == 'c') cc[a] = 1;
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;        
        if(cc[a]) g[a].push_back(b);
        else g[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        if(cc[i]){
            fill(ch.begin(), ch.end(), 0);
            if(bipartiteMatching(i)) ans--;
        }
    }
    cout << ans;
}
	

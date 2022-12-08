// 2022-12-08
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
    int a, b, c;
};

int f(st x, st y){
    if(x.a == y.a && x.b == y.b && x.c == y.c) return 2;
    if(x.a >= y.a && x.b >= y.b && x.c >= y.c) return 1;
    return 0;
}

vector<int> g[51];
vector<int> ch(51);
vector<int> match(51);

bool bipartiteMatching(int x)
{
    for (int i{0}; i < (int)g[x].size(); ++i)
    {
        int nx{g[x][i]};
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

int main() {
	fastio;
    int n;
    cin >> n;
    vector<st> vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            if(i == j) continue;
            int a = f(vec[i], vec[j]);
            if(a == 1) g[i].push_back(j);
            else if(a == 2 && i < j) g[i].push_back(j);
        }
    }   
    int ans{0};
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j < 2; ++j){
            fill(ch.begin(), ch.end(), 0);
            bipartiteMatching(i);
        }
    }
    for(int i{1}; i <= n; ++i){
        if(match[i] == 0) ans++;
    }
    cout << ans;
}
	

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

vector<int> g[1001];
vector<int> ch(1001);
vector<int> match(1001, -1);

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
    map<string, int> mp;
    for(int i{0}; i < m; ++i){
        string str;
        cin >> str;
        mp[str] = i;
    }
    for(int i{0}; i < n; ++i){
        int k;
        cin >> k;
        for(int j{0}; j < k; ++j){
            string str;
            cin >> str;
            g[i].push_back(mp[str]);
        } 
    }
    int cnt{0};
    for(int i{0}; i < n; ++i){
        fill(ch.begin(), ch.end(), 0);
        if(bipartiteMatching(i)) {
            cnt++;
        }
    }
    if(cnt == n) cout << "YES";
    else {
        cout << "NO\n" << cnt;
    }
}
	

// 2022-01-12
#include <bits/stdc++.h>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

vector<int> graph[1001];
vector<int> ch(1001);
vector<int> match(1001);
vector<int> A, B;

bool bipartiteMatching(int x)
{
    for (int i{0}; i < (int)graph[x].size(); ++i)
    {
        int nx{graph[x][i]};
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

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i{1}; i <= n; ++i)
    {
        int a;
        cin >> a;
        for (int j{0}; j < a; ++j)
        {
            int k;
            cin >> k;
            graph[i].push_back(k);
        }
    }
    int ans{0};
    for (int i{1}; i <= n; ++i)
    {
        fill(ch.begin(), ch.end(), 0);
        if (bipartiteMatching(i))
            ans++;
    }
    for (int i{1}; i <= n; ++i)
    {
        while (k && bipartiteMatching(i))
        {
            ans++;
            k--;
        }
    }
    cout << ans;
}
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

vector<int> ch(1001);
vector<int> match(1001);
vector<int> A, B;
int prime[2001]{};
vector<int> graph[1001];
vector<int> vec;

bool bipartiteMatching(int x)
{
    for (int i{0}; i < (int)graph[x].size(); ++i)
    {
        int nx{graph[x][i]};
        if (ch[nx] == 0)
        {
            if (match[nx] == vec.front())
                continue;
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
    fastio;
    prime[1] = 1;
    for (int i{2}; i <= 2000; ++i)
    {
        if (prime[i] == 0)
        {
            for (int j{i * 2}; j <= 2000; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    int n;
    cin >> n;
    vec.resize(n);
    for (int i{0}; i < n; ++i)
    {
        cin >> vec[i];
        if (vec[i] % 2 == vec.front() % 2)
            A.push_back(vec[i]);
        else
            B.push_back(vec[i]);
    }
    for (int i{0}; i < (int)A.size(); ++i)
    {
        for (int j{0}; j < (int)B.size(); ++j)
        {
            if (prime[A[i] + B[j]] == 0)
            {
                graph[A[i]].push_back(B[j]);
            }
        }
    }
    vector<int> ans;
    int cnt{1};
    for (int i{0}; i < (int)B.size(); ++i)
    {
        cnt = 1;
        if (prime[vec.front() + B[i]] == 0)
        {
            match[B[i]] = vec.front();
        }
        else
            continue;
        for (int j{1}; j < (int)A.size(); ++j)
        {
            fill(ch.begin(), ch.end(), 0);
            if (bipartiteMatching(A[j]))
                cnt++;
        }
        fill(match.begin(), match.end(), 0);
        if (cnt == n / 2)
            ans.push_back(B[i]);
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
    {
        cout << -1;
        return 0;
    }
    for (auto &i : ans)
        cout << i << " ";
}
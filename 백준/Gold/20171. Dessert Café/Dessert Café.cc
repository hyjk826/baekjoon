// 2022-11-13
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<vi> g(100001);
int n, k;
vi cnt(100001);
int ans{0};

void dfs(int cur, int pre){
    for(auto& i : g[cur]){
        if(i == pre) continue;
        dfs(i, cur);
        cnt[cur] += cnt[i];
    }
    if(cnt[cur] == 0) ans++;
    else{
        for(auto& i : g[cur]){
            if(cnt[i] == k){
                ans++;
                break;
            }
        }
    }
}

int main() {
	fastio;
    cin >> n >> k;
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        cnt[a]++;
    }
    dfs(1, -1);
    cout << n - ans;
}
	


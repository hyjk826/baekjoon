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
    int n;
    cin >> n;
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi sub(n);
    ll sum{0};
    function<void(int,int)> dfs = [&](int cur, int pre){
        sub[cur] = 1;
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            dfs(i.first, cur);
            sub[cur] += sub[i.first];
            sum += 1LL * i.second * sub[i.first];
        }
    };
    dfs(0, -1);
    vl A(n);
    A[0] = sum;
    function<void(int,int)> dfs2 = [&](int cur, int pre){
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            A[i.first] = A[cur] + 1LL * i.second * (n - 2 * sub[i.first]);
            dfs2(i.first, cur);
        }
    };
    dfs2(0, -1);
    int idx1 = min_element(A.begin(), A.end()) - A.begin();
    int m;
    cin >> m;
    vector<vp> g2(m + 1);
    for(int i{0}; i < m - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g2[a].push_back({b, c});
        g2[b].push_back({a, c});
    }
    vi sub2(m);
    sum = 0;
    function<void(int,int)> f = [&](int cur, int pre){
        sub2[cur] = 1;
        for(auto& i : g2[cur]){
            if(i.first == pre) continue;
            f(i.first, cur);
            sub2[cur] += sub2[i.first];
            sum += 1LL * i.second * sub2[i.first];
        }
    };
    f(0, -1);
    vl B(m);
    B[0] = sum;
    function<void(int,int)> ff = [&](int cur, int pre){
        for(auto& i : g2[cur]){
            if(i.first == pre) continue;
            B[i.first] = B[cur] + 1LL * i.second * (m - 2 * sub2[i.first]);
            ff(i.first, cur);
        }
    };
    ff(0, -1);
    int idx2 = min_element(B.begin(), B.end()) - B.begin();
    cout << idx1 + 1 << " " << idx2 + 1 << "\n";
    cout << 1LL * A[idx1] * m + 1LL * B[idx2] * n + 1LL * n * m;
}
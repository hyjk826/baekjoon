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

vi manacher(vl& B){
    vl s((int)B.size() * 2 + 1, -LLONG_MAX);
    for(int i{0}; i < (int)B.size(); ++i){
        s[i * 2 + 1] = B[i];
    }
    int n = (int)s.size();
    int r{0}, p{0};
    vi A(n);
    for(int i{0}; i < n; ++i){
        if(i <= r) A[i] = min(r - i, A[2 * p - i]);
        else A[i] = 0;
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && s[i - A[i] - 1] ==s[i + A[i] + 1]) A[i]++;
        if(r < i + A[i]){
            r = i + A[i];
            p = i;
        }
    }
    return A;
}

vi A;

// 0_based
bool is_palin(int l, int r){
    if(A[l + r + 1] >= r - l + 1) return true;
    else return false;
}

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
    }
    vi in(n + 1), out(n + 1);
    vp X;
    int pv{0};
    function<void(int,int,int)> dfs = [&](int cur, int pre, int h){
        X.push_back({vec[cur], h});
        in[cur] = pv++;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur, h + 1);
            X.push_back({vec[cur], h});
            pv++;
        }
        out[cur] = pv - 1;
    };
    dfs(1, 0, 0);
    vl B;
    for(auto& i : X){
        B.push_back({((ll)i.first << 30LL) | i.second});
    }
    A = manacher(B);
    vi ans;
    for(int i{1}; i <= n; ++i){
        if(is_palin(in[i], out[i])) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << " ";
}

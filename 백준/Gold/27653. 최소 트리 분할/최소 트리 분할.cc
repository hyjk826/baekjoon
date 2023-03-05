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

const int sz = 1e5 + 10;
int p[sz];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].second;
        vec[i].first = i;
    }
    sort(vec.begin(), vec.end(), [&](pi a, pi b){
        return a.second > b.second;
    });
    vector<vi> g(n);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans{0};
    ans += vec.back().second;
    vi ch(n);
    vector<vi> A;
    vi B;
    A.push_back({vec[0].first});
    B.push_back(vec[0].second);
    for(int i{1}; i < n; ++i){
        if(vec[i].second == B.back()) A.back().push_back(vec[i].first);
        else {
            A.push_back({vec[i].first});
            B.push_back(vec[i].second);
        }
    }
    for(int i{0}; i < n; ++i) p[i] = i;
    int cnt{0};
    for(auto& i : A[0]){
        ch[i] = 1;
        cnt++;
        for(auto& j : g[i]){
            if(ch[j] && merge(i, j)) cnt--;
        }
    }
    for(int i{1}; i < (int)A.size(); ++i){
        ans += 1LL * cnt * (B[i - 1] - B[i]);
        for(auto& j : A[i]){
            ch[j] = 1;
            cnt++;
            for(auto& k : g[j]){
                if(ch[k] && merge(j, k)) cnt--;
            }
        }
    }
    cout << ans;
}

// 2022-07-29
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

int n, m;
vi uni(200001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

int main() {
	fastio;
    cin >> n >> m;
    vi par(n + 1);
    for(int i{2}; i <= n; ++i){
        int a;
        cin >> a;
        par[i] = a;
        uni[i] = i;
    }
    uni[1] = 1;
    vp query(n - 1 + m);
    for(int i{0}; i < n - 1 + m; ++i){
        int c;
        cin >> c;
        if(c == 1){
            cin >> query[i].first >> query[i].second;
        }
        else{
            cin >> query[i].first;
        }
    }
    vi ans;
    for(int i{n - 2 + m}; i >= 0; --i){
        if(query[i].second == 0){
            int a = query[i].first;
            int b = par[a];
            Union(a, b);
        }
        else{
            int a = query[i].first;
            int b = query[i].second;
            if(find(a) == find(b)) ans.push_back(1);
            else ans.push_back(0);
        }
    }    
    reverse(ans.begin(), ans.end());
    for(auto& i : ans){
        if(i == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}


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

vi p((int)1e5 + 1);
vector<set<int> > st((int)1e5 + 1);

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(st[a].size() < st[b].size()){
            for(auto& i : st[a]){
                st[b].insert(i);
            }
            p[a] = b;
        }
        else{
            for(auto& i : st[b]){
                st[a].insert(i);
            }
            p[b] = a;
        }
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    vi par(n + 1);
    for(int i{2}; i <= n; ++i){
        cin >> par[i];
    }
    vi color(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> color[i];
    }
    vp Q(n - 1 + q);
    for(int i{0}; i < n - 1 + q; ++i){
        cin >> Q[i].first >> Q[i].second;
    }
    reverse(Q.begin(), Q.end());
    vi ans;
    for(int i{1}; i <= n; ++i){
        p[i] = i;
        st[i].insert(color[i]);
    }
    for(int i{0}; i < n - 1 + q; ++i){
        if(Q[i].first == 1){
            int a =Q[i].second;
            merge(a, par[a]);
        }
        else{
            int a = Q[i].second;
            ans.push_back(st[find(a)].size());
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << "\n";
}

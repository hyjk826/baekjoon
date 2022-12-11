// 2022-12-11
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

struct node{
    map<string, node> mp;
}root;

void insert(int L, node& cur, vs& vec){
    if(L == (int)vec.size()) return;
    if(!cur.mp.count(vec[L])) cur.mp[vec[L]] = node();
    insert(L + 1, cur.mp[vec[L]], vec);
}

void dfs(int L, node& cur){
    for(auto& i : cur.mp){
        cout << string(2 * L, '-');
        cout << i.first << "\n";
        dfs(L + 1, i.second);
    }
}

int main() {
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vs vec(m);
        for(int i{0}; i < m; ++i) cin >> vec[i];
        insert(0, root, vec);
    }    
    dfs(0, root);
}
	

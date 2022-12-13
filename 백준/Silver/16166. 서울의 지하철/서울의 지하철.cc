// 2022-12-12
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

struct st{
    int a, b, c;
};

int main() {
	fastio;
    int n;
    cin >> n;
    map<int, vp> mp; 
    vi A;
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vi vec(m);
        for(int j{0}; j < m; ++j){
            cin >> vec[j];
            if(vec[j] == 0) A.push_back(i);
        }
        for(int j{0}; j < m - 1; ++j){
            mp[vec[j]].push_back({vec[j + 1], i});
            mp[vec[j + 1]].push_back({vec[j], i});
        }
    }
    int e;
    cin >> e;
    queue<st> Q;
    for(auto& i : A){
        Q.push({0, i, 0});
    }
    map<int, int> ans;
    ans[0] = 0;
    while(!Q.empty()){
        int x{Q.front().a};
        int pre{Q.front().b};
        int c {Q.front().c};
        Q.pop();
        for(auto& i : mp[x]){
            int nd = c;
            if(i.second != pre) nd++;
            if(!ans.count(i.first) || ans[i.first] > nd){
                ans[i.first] = nd;
                Q.push({i.first, i.second, nd});
            }
        }
    }
    if(!ans.count(e)) cout << -1;
    else cout << ans[e];
}
	

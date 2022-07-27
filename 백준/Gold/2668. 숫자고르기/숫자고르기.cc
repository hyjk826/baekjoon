// 2022-07-28
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

vi graph[101];
vi ans;
vi ch(101);

void dfs(int k, int i){
    for(auto& j : graph[k]){
        if(ch[j] == 0){
            ch[j] = 1;
            dfs(j, i);
        }
        else{
            if(j == i){
                ans.push_back(i);
            }
        }
    }
}

int main() {
	fastio;
    int n;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        graph[i].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        fill(ch.begin(), ch.end(), 0);
        ch[i] = 1;
        dfs(i, i);
    }
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << "\n";
}


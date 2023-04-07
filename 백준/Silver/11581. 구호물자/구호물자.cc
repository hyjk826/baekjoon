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
    vector<vi> g(n + 1);
    for(int i{1}; i <= n - 1; ++i){
        int m;
        cin >> m;
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            g[i].push_back(a);
        }
    }
    vi ch(n + 1);
    function<void(int)> dfs = [&](int cur){
        for(auto& i : g[cur]){
            if(ch[i] == 0){
                ch[i]= 1;
                dfs(i);
                ch[i] = 0;
            }
            else{
                cout << "CYCLE"; exit(0);
            }
        }
    };
    dfs(1);
    cout << "NO CYCLE";
}

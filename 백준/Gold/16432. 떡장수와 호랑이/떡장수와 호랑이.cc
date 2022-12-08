// 2022-12-08
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

int main() {
	fastio;
	int n;
    cin >> n;
    vector<vi> ch(n, vi(10));
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            if(i == 0) ch[i][a] = 1;
            else{
                for(int k{1}; k < 10; ++k){
                    if(ch[i - 1][k] == 0 || k == a) continue;
                    ch[i][a] = k;
                    break;
                }
            }
        }
    }
    for(int i{1}; i < 10; ++i){
        if(ch[n - 1][i] == 0) continue;
        vi ans;
        int x = i;
        ans.push_back(x);
        for(int j{n - 1}; j >= 1; --j){
            ans.push_back(ch[j][x]);
            x = ch[j][x];
        }
        reverse(ans.begin(), ans.end());
        for(auto& j : ans) cout << j << "\n";
        return 0;
    }
    cout << -1;
}
	

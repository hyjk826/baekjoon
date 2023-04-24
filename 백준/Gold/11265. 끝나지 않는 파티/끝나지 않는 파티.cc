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
    int n, q;
    cin >> n >> q;
    vector<vi> floyd(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> floyd[i][j];
        }
    }
    for(int k{0}; k < n; ++k){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if(floyd[a][b] <= c) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}

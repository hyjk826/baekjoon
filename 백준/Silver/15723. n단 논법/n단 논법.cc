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

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> floyd(26, vi(26, (int)1e8));
    for(int i{0}; i < 26; ++i){
        floyd[i][i] = 0;
    }
    for(int i{0}; i < n; ++i){
        char a, c; string b;
        cin >> a >> b >> c;
        floyd[a - 'a'][c - 'a'] = 1;
    }
    for(int k{0}; k < 26; ++k){
        for(int i{0}; i < 26; ++i){
            for(int j{0}; j < 26; ++j){
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        char a, c; string b;
        cin >> a >> b >> c;
        if(floyd[a - 'a'][c - 'a'] != (int)1e8) cout << "T\n";
        else cout << "F\n";
    }
}
	

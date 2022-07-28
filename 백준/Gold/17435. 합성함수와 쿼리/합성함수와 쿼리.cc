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

vector<vi> par(500001, vi(20, -1));

int main() {
	fastio;
    int n;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        par[i][0] = a;
    }
    for(int i{1}; i < 20; ++i){
        for(int j{1}; j <= n; ++j){
            if(par[j][i - 1] == -1) continue;
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        for(int i{0}; a > 0; ++i){
            if(a & 1) b = par[b][i];
            a >>= 1;
        }
        cout << b << "\n";
    }
}


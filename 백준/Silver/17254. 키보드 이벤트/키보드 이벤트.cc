// 2022-11-21
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

vector<vp> g((int)1e6 + 1);

int main() {
	fastio;	
	int n, m;
    cin >> n >> m; 
    for(int i{0}; i < m; ++i){
        int a, b;
        char c;
        cin >> a >> b >> c;
        g[b].push_back({a, c - 'A'});
    }
    for(int i{0}; i <= (int)1e6; ++i){
        sort(g[i].begin(), g[i].end(), [&](pi a, pi b){
            return a.first < b.first;
        });
    }
    for(int i{0}; i <= (int)1e6; ++i){
        for(auto& j : g[i]){
            cout << char('A' + j.second);
        }
    }
}
	


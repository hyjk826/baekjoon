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
    vector<vector<vc> > vec(n, vector<vc>(5, vc(7)));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 5; ++j){
            for(int k{0}; k < 7; ++k){
                cin >> vec[i][j][k];
            }
        }
    }
    int mn{MAX};
    pi ans;
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            int dif{0};
            for(int a{0}; a < 5; ++a){
                for(int b{0}; b < 7; ++b){
                    if(vec[i][a][b] != vec[j][a][b]) dif++;
                }
            }
            if(dif < mn){
                mn = dif;
                ans = {i + 1, j + 1};
            }
        }
    }
    cout << ans.first << " " << ans.second;
}

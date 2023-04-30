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

bool A[300][300];
bool B[300][300];

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> A[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> B[i][j];
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            int res{0};
            for(int k{0}; k < n; ++k){
                res |= (A[i][k] & B[k][j]);
            }
            if(res) ans++;
        }
    }
    cout << ans;
}

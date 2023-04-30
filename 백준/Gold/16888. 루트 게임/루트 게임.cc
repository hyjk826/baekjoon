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

int dp[1000001];

int main(){
	fastio;
    for(int i{1}; i <= 1000000; ++i){
        for(int j{1}; j * j <= i; ++j){
            if(dp[i - j * j] == 0){
                dp[i] =  1; break;
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(dp[n]) cout << "koosaga\n";
        else cout << "cubelover\n";
    }
}

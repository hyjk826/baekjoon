// 2022-12-30
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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi dp;
        dp.push_back(1);
        dp.push_back(1);
        while(1){
            dp.push_back((dp.back() + dp[(int)dp.size() - 2]) % m);
            if(dp.back() == 1 && dp[(int)dp.size() - 2] == 1){
                cout << n << " " << dp.size() - 2 << "\n";
                break;
            }
        }
    }
}

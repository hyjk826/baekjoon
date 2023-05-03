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
    t = 3;
    while(t--){
        int n;
        cin >> n;
        vp vec(n);
        int sum{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i].first >> vec[i].second;
            sum += vec[i].first * vec[i].second;
        }
        if(sum & 1) cout << 0 << "\n";
        else{
            vi A;
            for(int i{0}; i < n; ++i){
                int k{1};
                while(k <= vec[i].second){
                    A.push_back(vec[i].first * k);
                    k *= 2;
                }
                k /= 2;
                if(vec[i].second - k) A.push_back(vec[i].first * k);
            }
            sum /= 2;
            vi dp(sum + 1);
            dp[0] = 1;
            for(auto& i : A){
                for(int j{sum - i}; j >= 0; --j){
                    if(dp[j]) dp[j + i] = 1;
                }
            }
            if(dp[sum]) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}

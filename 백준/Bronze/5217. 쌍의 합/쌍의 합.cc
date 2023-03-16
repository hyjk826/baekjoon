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
        int n;
        cin >> n;
        cout << "Pairs for " << n << ": ";
        vp ans;
        for(int i{1}; i <= n; ++i){
            int a = i;
            int b = n - i;
            if(a < b){
                ans.push_back({a, b});
            }
        }
        for(int i{0}; i < (int)ans.size(); ++i){
            cout << ans[i].first << " " << ans[i].second;
            if(i < (int)ans.size() - 1) cout << ", ";
        }
        cout << "\n";
    }
}

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
        int k, n;
        cin >> k >> n;
        vi A(n), B(n), C(n), D(n);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        for(int i{0}; i < n; ++i){
            cin >> B[i];
        }
        for(int i{0}; i < n; ++i){
            cin >> C[i];
        }
        for(int i{0}; i < n; ++i){
            cin >> D[i];
        }
        vi X, Y;
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                X.push_back(A[i] + B[j]);
                Y.push_back(C[i] + D[j]);
            }
        }
        sort(Y.begin(), Y.end());
        int ans{MAX};
        int mn{MAX};
        for(auto& i : X){
            auto it = lower_bound(Y.begin(), Y.end(), k - i);
            if(it != Y.end()){
                int diff = abs(k - (*it + i));
                if(diff < mn){
                    mn = diff;
                    ans = *it + i;
                }
                else if(diff == mn){
                    ans = min(ans, *it + i);
                }
            }
            if(it != Y.begin()){
                it--;
                int diff = abs(k - (*it + i));
                if(diff < mn){
                    mn = diff;
                    ans = *it + i;                    
                }
                else if(diff == mn){
                    ans = min(ans, *it + i);
                }
            }
        }
        cout << ans << "\n";
    }
}

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
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vi A(n), B(m);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        } 
        for(int i{0}; i < m; ++i){
            cin >> B[i];
        }
        int ans{0};
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(auto& i : A){
            ans += upper_bound(B.begin(), B.end(), i) - lower_bound(B.begin(), B.end(), i);
        }
        cout << ans << "\n";
    }
}

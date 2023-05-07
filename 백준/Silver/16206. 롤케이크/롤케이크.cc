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
    cin >> n >> m;
    vi A, B;
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a % 10 == 0) A.push_back(a);
        else B.push_back(a);
    }
    sort(A.begin(), A.end());
    for(auto& i : A){
        if(m >= i / 10 - 1){
            ans += i / 10;
            m -= i / 10 - 1;
        }
        else{            
            ans += m;
            m = 0;
            break;
        }
    }
    for(auto& i : B){
        int k = min(m, i / 10);
        ans += k;
        m -= k;
        if(m == 0) break;
    }
    cout << ans;
}

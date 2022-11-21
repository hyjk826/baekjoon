// 2022-11-20
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

int main() {
	fastio;	
	ll n, w;
    cin >> n >> w;
    vl A, B;
    for(int i{0}; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        if(a == 3) A.push_back(b);
        else B.push_back(b);
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    A.insert(A.begin(), 0);
    B.insert(B.begin(), 0);
    for(int i{1}; i < (int)A.size(); ++i){
        A[i] += A[i - 1];
    }
    for(int i{1}; i < (int)B.size(); ++i){
        B[i] += B[i - 1];
    }
    ll ans{0};
    for(int i{0}; i < (int)A.size(); ++i){
        if(i * 3 > w) break;
        ll r = (w - i * 3) / 5;
        ans = max(ans, A[i] + B[min((ll)B.size() - 1, r)]);
    }
    cout << ans;
}
	


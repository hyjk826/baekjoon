// 2023-01-17
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

void solve(){
	int n;
    cin >> n;
    vi vec(n);
    vi A, B;
    vi a, b;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        if(vec[i] & 1){
            A.push_back(vec[i]);
            a.push_back(i);
        }
        else{
            B.push_back(vec[i]);
            b.push_back(i);
        }
    }
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    vi ans(n);
    for(int i{0}; i < (int)A.size(); ++i){
        ans[a[i]] = A[i];
    }
    for(int i{0}; i < (int)B.size(); ++i){
        ans[b[i]] = B[i];
    }
    for(auto& i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
	fastio;	
	int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": ";
        solve();
    }
}
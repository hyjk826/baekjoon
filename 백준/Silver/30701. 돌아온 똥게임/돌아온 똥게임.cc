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
	ll n, d;
    cin >> n >> d;
    vl A, B;
    for(ll i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 1) A.push_back(b);
        else B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idx{0};
    int ans{0};
    for(int i{0}; i < (int)A.size(); ++i){
        if(d > A[i]){
            d += A[i];
            d = min(d, (ll)1e9 + 1);
            ans++;
        }
        else{
            if(idx == (int)B.size()) break;
            d = min(d * B[idx++], (ll)1e9 + 1);
            i--;
        }
    }
    cout << ans + (int)B.size() << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

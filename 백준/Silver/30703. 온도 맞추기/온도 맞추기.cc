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
    vi A(n), B(n);
    vi X(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    for(auto& i : X) cin >> i;
    vi tmp;
    for(int i{0}; i < n; ++i){
        if(abs(A[i] - B[i]) % X[i] == 0){
            tmp.push_back({abs(A[i] - B[i]) / X[i]});
        }
        else{
            cout << -1 << "\n"; return;
        }
    }
    bool ok = true;
    for(int i{1}; i < (int)tmp.size(); ++i){
        ok &= ((tmp[i] - tmp[i - 1]) % 2 == 0);
    }
    if(ok) cout << *max_element(tmp.begin(), tmp.end()) << "\n";
    else cout << -1 << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

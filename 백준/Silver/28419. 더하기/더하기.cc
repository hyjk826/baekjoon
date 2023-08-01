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
    ll odd{0}, even{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        if(i & 1) odd += vec[i];
        else even += vec[i];
    }
    if(n == 3){
        if(even == odd) cout << 0 << "\n";
        else if(even > odd) cout << -1 << "\n";
        else cout << odd - even << "\n";
    }
    else cout << abs(odd - even) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

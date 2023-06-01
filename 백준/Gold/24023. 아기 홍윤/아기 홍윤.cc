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
    int n, k;
    cin >> n >> k;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    int pre{0};
    int sum{0};
    for(int i{1}; i <= n; ++i){
        bool ok = true;
        for(int j{0}; j < 30; ++j){
            if((vec[i] & k) == vec[i]) continue;
            ok = false;
        }
        if(!ok){
            if(sum == k){
                cout << pre + 1 << " " << i - 1; return;
            }
            pre = i;
            sum = 0;
        }
        else sum |= vec[i];
    }
    if(sum == k){
        cout << pre + 1 << " " << n; return;
    }
    cout << -1;
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}

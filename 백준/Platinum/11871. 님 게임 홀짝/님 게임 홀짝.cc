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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n;
    cin >> n;
    int mex{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a & 1) mex ^= (a + 1) / 2;
        else{
            mex ^= (a / 2 - 1);
        }
    }
    if(mex) cout << "koosaga";
    else cout << "cubelover";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

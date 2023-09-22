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
    if(n % 4763 == 0){
        n /= 4763;
        vi A = {508, 108};
        vi B = {212, 305};
        vp ans;
        for(int i{0}; i <= 200; ++i){
            for(int j{0}; j < 2; ++j){
                for(int k{0}; k < 2; ++k){
                    int tmp = n;
                    tmp -= A[j] * i;
                    if(tmp < 0) continue;
                    if(tmp % B[k] == 0) {
                        if(tmp / B[k] > 200) continue;
                        ans.push_back({i, tmp / B[k]});
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans.size() << "\n";
        for(auto& i: ans) cout << i.first << " " << i.second << "\n";
    }
    else cout << 0 << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

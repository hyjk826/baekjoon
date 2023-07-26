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
    multiset<int> ms;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a < k) ms.insert(a);
    }
    int ans{0};
    while(!ms.empty()){
        int a = *ms.begin();
        auto it = ms.upper_bound(k - a);
        if(it == ms.begin() || prev(it) == ms.begin()) break;
        it--;
        ms.erase(it);
        ms.erase(ms.begin());
        ans++;
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

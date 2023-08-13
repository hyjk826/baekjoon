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
    int mx{0};
    priority_queue<int, vi, greater<int> > pQ;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        mx = max(mx, vec[i]);
    }
    for(int i{0}; i < n; ++i){
        while(vec[i] <= mx / 2) vec[i] *= 2;
        pQ.push(vec[i]);
    }
    int ans = mx - *min_element(vec.begin(), vec.end());
    for(int i{0}; i < n; ++i){
        int x = pQ.top();
        pQ.pop();
        pQ.push(x * 2);
        mx = max(mx, x * 2);
        ans = min(ans, mx - pQ.top());
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

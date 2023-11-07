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
	int n, t, p;
    cin >> n >> t >> p;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    priority_queue<int> pQ;
    int sum{0};
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(i * p > t) break;
        pQ.push(vec[i]);
        sum += vec[i];
        while(!pQ.empty() && sum + p * i > t){
            sum -= pQ.top();
            pQ.pop();
        }
        ans = max(ans, (int)pQ.size());
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

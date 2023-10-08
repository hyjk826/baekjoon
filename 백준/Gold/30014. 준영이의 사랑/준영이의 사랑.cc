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
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    deque<int> dQ;
    dQ.push_back(vec.back());
    vec.pop_back();
    while(!vec.empty()){
        if(dQ.back() >= dQ.front()) dQ.push_back(vec.back());
        else dQ.push_front(vec.back());
        vec.pop_back();
    }
    ll ans{0};
    for(int i{0}; i < n; ++i){
        ans += 1LL * dQ[i] * dQ[(i + 1) % n];
    }
    cout << ans << "\n";
    for(auto& i : dQ) cout << i << " ";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

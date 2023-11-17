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
	deque<int> dQ;
    int n;
    cin >> n;
    dQ.push_back(n);
    for(int i{n - 1}; i >= 1; --i){
        if(i & 1) dQ.push_front(i);
        else dQ.push_back(i);
    }
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

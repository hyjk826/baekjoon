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
    for(auto& i : vec) cin >> i;
    set<int> st;
    vi ch(n + 1);
    for(auto& i : vec){
        auto it = st.lower_bound(i);
        int a, b;
        a = b = n;
        if(it != st.begin()) a = *prev(it);
        if(it != st.end()) b = *it;
        ch[i] = max(ch[a], ch[b]) + 1;
        st.insert(i);
    }
    cout << accumulate(ch.begin(), ch.end(), 0LL) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

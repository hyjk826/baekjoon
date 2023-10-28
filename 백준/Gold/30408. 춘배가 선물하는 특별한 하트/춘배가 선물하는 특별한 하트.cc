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
	ll a, b;
    cin >> a >> b;
    queue<ll> Q;
    Q.push(a);
    set<ll> st;
    st.insert(a);
    while(!Q.empty()){
        ll x{Q.front()};
        Q.pop();
        if(x == b){
            cout << "YES\n"; return;
        }
        if(x % 2 == 0){
            if(st.count(x / 2)) continue;
            st.insert(x / 2);
            Q.push(x / 2);
        }
        else{
            if(!st.count(x / 2)) {
                Q.push(x / 2);
                st.insert(x / 2);
            }
            if(!st.count(x / 2 + 1)){
                Q.push(x / 2 + 1);
                st.insert(x / 2 + 1);
            }
        }
    }
    cout << "NO\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

// 2022-09-13
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    ll a, b;
    cin >> a >> b;
    set<ll> st;
    queue<pi> Q;
    Q.push({a, 0});
    st.insert(a);
    while(!Q.empty()){
        ll x{Q.front().first};
        ll cnt{Q.front().second};
        Q.pop();
        if(x == b){
            cout << cnt + 1;
            return 0;
        }
        if(x * 2 <= b && !st.count(x * 2)){
            st.insert(x * 2);
            Q.push({x * 2, cnt + 1});
        }
        if(x * 10 + 1 <= b && !st.count(x * 10 + 1)){
            st.insert(x * 10 + 1);
            Q.push({x * 10 + 1, cnt + 1});
        }
    }
    cout << -1;
}
	


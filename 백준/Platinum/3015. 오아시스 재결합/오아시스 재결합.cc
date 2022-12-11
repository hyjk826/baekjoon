// 2022-12-11
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll ans{0};
    stack<pi> st;
    for(int i{0}; i < n; ++i){
        int k{1};
        while(!st.empty() && st.top().first <= vec[i]){
            ans += st.top().second;
            if(st.top().first == vec[i]) k = st.top().second + 1;
            st.pop();
        }
        if(!st.empty()) ans++;
        st.push({vec[i], k});
    }
    cout << ans;
}
	

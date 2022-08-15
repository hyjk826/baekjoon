// 2022-08-15
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
    ll n, k;
    cin >> n >> k;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    set<ll> st;
    st.insert(1);
    priority_queue<ll, vl, greater<ll> > pQ;
    pQ.push(1);
    ll mx{1};
    while(k--){
        ll x{pQ.top()};
        pQ.pop();
        for(auto& i : vec){
            if(1LL * x * i > (1LL << 31)) break;
            if(!st.count(x * i)) {
                if(pQ.size() > k && x * i > mx) break;
                mx = max(mx, x * i);
                pQ.push(x * i);
                st.insert(x * i);
            }
        }
    }
    cout << pQ.top();
}


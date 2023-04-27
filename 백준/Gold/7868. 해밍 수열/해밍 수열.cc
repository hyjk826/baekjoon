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

int main(){
    int p1, p2, p3, n;
    cin >> p1 >> p2 >> p3 >> n;
    priority_queue<ll, vl, greater<ll> > pQ;
    pQ.push(1);
    set<ll> st;
    while(n--){
        ll x{pQ.top()};
        pQ.pop();
        if(x <= (ll)1e18 / p1 && !st.count(x * p1)) {
            st.insert(x * p1);            
            pQ.push(x * p1);
        }        
        if(x <= (ll)1e18 / p2 && !st.count(x * p2)) {
            st.insert(x * p2);            
            pQ.push(x * p2);
        }        
        if(x <= (ll)1e18 / p3 && !st.count(x * p3)) {
            st.insert(x * p3);            
            pQ.push(x * p3);
        }        
    }
    cout << pQ.top();
}

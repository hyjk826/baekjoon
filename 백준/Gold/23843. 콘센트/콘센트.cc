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
	fastio;
    int n, m;
    cin >> n >> m;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.rbegin(), vec.rend());
    priority_queue<ll, vl, greater<ll> > pQ;
    for(int i{0}; i < m; ++i){
        pQ.push(vec[i]);
    }
    for(int i{m}; i < n; ++i){
        int a = pQ.top();
        pQ.pop();
        pQ.push(a + vec[i]);
    }
    ll ans{0};
    while(!pQ.empty()){
        ans = pQ.top();
        pQ.pop();
    }
    cout << ans;
}

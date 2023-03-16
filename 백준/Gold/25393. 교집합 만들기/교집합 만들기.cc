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
    int n;
    cin >> n;
    vi A((int)1e6 + 1, -1), B((int)1e6 + 1, MAX);
    set<pi> st;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        st.insert({a, b});
        A[a] = max(A[a], b);
        B[b] = min(B[b], a);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(st.count({a, b})) {
            cout << 1 << "\n"; continue;
        }
        if(A[a] >= b && B[b] <= a) cout << 2 << "\n";
        else cout << -1 << "\n";
    }
}

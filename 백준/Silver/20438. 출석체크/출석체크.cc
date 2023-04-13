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
    int n, k, q, m;
    cin >> n >> k >> q >> m;
    vi ch(n + 10);
    set<int> st;
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        st.insert(a);
    }
    for(int i{3}; i <= n + 2; ++i) ch[i] = 1;
    for(int i{0}; i < q; ++i){
        int a;
        cin >> a;
        if(st.count(a)) continue;
        for(int j{a}; j <= n + 2; j += a){
            if(st.count(j)) continue;
            ch[j] = 0;
        }
    }
    for(int i{4}; i <= n + 2; ++i){
        ch[i] += ch[i - 1];
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << ch[b] - ch[a - 1] << "\n";
    }
}

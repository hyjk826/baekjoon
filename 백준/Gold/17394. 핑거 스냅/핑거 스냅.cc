// 2022-12-15
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
    vi prime((int)1e5 + 1);
    prime[1] = 1;
    for(ll i{2}; i <= (int)1e5; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)1e5; j += i){
            prime[j] = 1;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        set<int> st;
        for(int i{a}; i <= b; ++i){
            if(prime[i]) continue;
            st.insert(i);
        }
        if(st.empty()) cout << -1 << "\n";
        else{
            queue<int> Q;
            Q.push(n);
            map<int, int> mp;
            mp[n] = 0;
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                if(st.count(x)){
                    cout << mp[x] << "\n";
                    break;
                }
                for(int i{0}; i < 4; ++i){
                    int nx = x;
                    if(i == 0) nx /= 2;
                    else if(i == 1) nx /= 3;
                    else if(i == 2) nx++;
                    else if(i == 3 && x >= 0) nx--;
                    if(!mp.count(nx)) {
                        mp[nx] = mp[x] + 1;
                        Q.push(nx);
                    }
                }
            }
        }
    }
}
	

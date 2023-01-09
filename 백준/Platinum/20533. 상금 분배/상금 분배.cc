// 2023-01-09
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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.rbegin(), vec.rend());
    vec.resize(min((int)vec.size(), 200));
    set<int> st;
    st.insert(vec[0]);
    ll ans{0};
    for(int i{1}; i < (int)vec.size() - 5; ++i){        
        for(int j{i + 1}; j <= (int)vec.size() - 5; ++j){
            ll sum{0};
            if(vec[i] + vec[j] < vec[j + 1] + vec[j + 2] + vec[j + 3] + vec[j + 4]){
                sum += vec[i] + vec[j] + vec[j + 1] + vec[j + 2] + vec[j + 3] + vec[j + 4];
            }
            else continue;
            auto it = st.lower_bound(vec[i]+ vec[j]);
            if(it == st.begin()) continue;
            it--;            
            if(*it < vec[i] + vec[j]){
                ans = max(ans, sum + *it);
            }
        }
        st.insert(vec[i]);
    }
    if(ans == 0) cout << -1;
    else cout << ans;
}

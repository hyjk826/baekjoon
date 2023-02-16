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

int f(pi a, pi b){
    int x = abs(a.first - b.first);
    int y = abs(a.second - b.second);
    return x * x + y * y;
}

int main() {
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    set<pi> st;
    st.insert({vec[0].second, vec[0].first});
    st.insert({vec[1].second, vec[1].first});
    int mn = f(vec[0], vec[1]);
    int k{0};
    for(int i{2}; i < n; ++i){
        while(k < i){            
            if((vec[i].first - vec[k].first) * (vec[i].first - vec[k].first) < mn) break;
            st.erase({vec[k].second, vec[k].first});
            k++;
        }
        auto l = st.lower_bound({vec[i].second - sqrt(mn), -MAX});
        auto r = st.lower_bound({vec[i].second + sqrt(mn), MAX});
        for(auto j{l}; j != r; ++j){
            mn = min(mn, f(vec[i], {j->second, j->first}));
        }
        st.insert({vec[i].second, vec[i].first});
    }    
    cout << mn;
}


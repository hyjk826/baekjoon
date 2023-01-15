#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long>
#define pi pair<int,int>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    if(n == 1){
        cout << 0 << "\n";
        return 0;
    }
    set<pi> st;
    ll sum{0};
    for(int i{0}; i < k; ++i){
        st.insert({vec[i], i});
    }
    ll ans{LLONG_MAX};
    for(auto i{next(st.begin())}; i != st.end(); ++i){
        sum += abs(i->second - prev(i)->second);
    }
    ans = sum;
    for(int i{k}; i < n; ++i){
        auto it = st.find({vec[i - k], i - k});
        if(it == st.begin()) sum -= abs(next(it)->second - it->second);
        else if(it == prev(st.end())) sum -= abs(prev(it)->second - it->second);
        else{
            sum -= abs(next(it)->second - it->second);
            sum -= abs(prev(it)->second - it->second);
            sum += abs(next(it)->second - prev(it)->second);
        }
        st.erase(it);
        st.insert({vec[i], i});
        it = st.find({vec[i], i});
        if(it == st.begin()) sum += abs(next(it)->second - it->second);
        else if(it == prev(st.end())) sum += abs(prev(it)->second - it->second);
        else{
            sum -= abs(next(it)->second - prev(it)->second);
            sum += abs(next(it)->second - it->second);
            sum += abs(prev(it)->second - it->second);
        }
        ans = min(ans, sum);
    }
    cout << ans;
}
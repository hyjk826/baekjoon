// 2022-09-01
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

vi LIS(vi& vec){
    int n = (int)vec.size();
    vi v;
    v.push_back(-MAX);
    vi cnt(n);
    for(int i{0}; i < n; ++i){
        if(v.back() < vec[i]){
            v.push_back(vec[i]);
            cnt[i] = v.size() - 1;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), vec[i]);
            cnt[i] = it - v.begin();
            *it = vec[i];
        }
    }
    vi ans;
    int idx{(int)v.size() - 1};
    for(int i{n - 1}; i >= 0; --i){
        if(cnt[i] == idx){
            ans.push_back(vec[i]);
            idx--;
        }
        if(idx == 0) break;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vp copy = vec;
    sort(copy.begin(), copy.end());
    vi A;
    for(auto& i : copy){
        A.push_back(i.second);
    }
    set<int> st;
    vi r = LIS(A);
    for(int i{0}; i < (int)r.size(); ++i){
        st.insert(r[i]);
    }
    cout << n - (int)r.size() << "\n";
    vi ans;
    for(int i{0}; i < n; ++i){
        if(st.count(vec[i].second)) continue;
        ans.push_back(vec[i].first);
    }
    sort(ans.begin(), ans.end());
    for(auto& i : ans){
        cout << i << "\n";
    }

}


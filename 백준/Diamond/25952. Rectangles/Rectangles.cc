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
    vp vec(n);
    vi A, B;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        A.push_back(vec[i].first);
        B.push_back(vec[i].second);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<unordered_set<int> > l1;
    vector<unordered_set<int> > s1;
    vector<vi> X(A.size());
    for(int i{0}; i < n; ++i){
        vec[i].first = lower_bound(A.begin(), A.end(), vec[i].first) - A.begin();
        vec[i].second = lower_bound(B.begin(), B.end(), vec[i].second) - B.begin();
        X[vec[i].first].push_back(vec[i].second);
    }
    ll ans{0};
    vector<vi> s2((A.size()));
    for(int i{0}; i < (int)X.size(); ++i){
        if(X[i].empty()) continue;
        unordered_set<int> st;
        if(X[i].size() >= 80){
            for(auto& j : X[i]){
                st.insert(j);
            }
            l1.push_back(st);
        }
        else{
            for(auto& j : X[i]){
                st.insert(j);
            }
            s1.push_back(st);
            s2[i] = X[i];
        }
    }
    for(auto& i : l1){        
        for(auto& j : s1){
            int cnt{0};
            for(auto& k : j){
                if(i.count(k)) {
                    cnt++;
                }
            }
            ans += 1LL * cnt * (cnt - 1) / 2;
        }        
    }
    for(int i{0}; i < (int)l1.size(); ++i){
        for(int j{i + 1}; j < (int)l1.size(); ++j){
            int cnt{0};
            for(auto& k : l1[i]){
                if(l1[j].count(k)) cnt++;
            }
            ans += 1LL * cnt * (cnt - 1) / 2;
        }
    }
    unordered_map<ll, int> mp;
    for(int i{0}; i <(int)s2.size(); ++i){
        if(s2[i].empty()) continue;
        for(int j{0}; j < (int)s2[i].size(); ++j){
            for(int k{j + 1}; k < (int)s2[i].size(); ++k){
                int a = min(s2[i][j], s2[i][k]);
                int b = max(s2[i][j], s2[i][k]);
                mp[(ll)a << 32 | b]++;
            }
        }
    }
    for(auto& i : mp){
        ans += 1LL * i.second * (i.second - 1) / 2;
    }
    cout << ans;
}

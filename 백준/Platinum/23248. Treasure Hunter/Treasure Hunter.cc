// 2022-09-06
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


int main() {
	fastio;
    int n, m, k;
    cin >> m >> n >> k;
    vp vec;
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }  
    sort(vec.begin(), vec.end());
    vi A;
    for(auto& i : vec){
        A.push_back(i.second);
    }
    set<int> st;
    map<int, vi> mp;
    int cnt{0};
    for(int i{0}; i < k; ++i){
        if(st.empty()){
            mp[A[i]].push_back(cnt);
            st.insert(A[i]);
            cnt++;
            continue;
        }
        auto it = st.upper_bound(A[i]);
        if(it == st.begin()){
           mp[A[i]].push_back(cnt);
           st.insert(A[i]);
           cnt++; 
        }
        else{
            --it;
            int k = mp[*it].back();
            mp[*it].pop_back();
            mp[A[i]].push_back(k);
            st.erase(it);
            st.insert(A[i]);
        }
    }
    cout << cnt;
}
	


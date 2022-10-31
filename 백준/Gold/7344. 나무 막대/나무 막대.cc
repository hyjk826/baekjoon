// 2022-10-31
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
#define MOD 100000007
using namespace std;

int main() {
	fastio;
	int t;
    cin >> t;
    while(t--){
        map<int, int> mp;
        int n;
        cin >> n;
        vp vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i].first >> vec[i].second;
        }
        sort(vec.begin(), vec.end());
        int k{0};
        set<int> st;
        for(int i{0}; i < n; ++i){
            int a = vec[i].second;
            auto it = st.upper_bound(a);
            if(it == st.begin()){
                mp[a] = k;
                st.insert(a);
                k++;
            }
            else{
                it--;
                mp[a] = mp[*it];
                mp.erase(*it);
                st.erase(*it);
                st.insert(a); 
            }
        }
        cout << k << "\n";
    }
}
	


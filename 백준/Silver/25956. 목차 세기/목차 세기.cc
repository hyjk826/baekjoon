// 2022-12-02
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
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    reverse(vec.begin(), vec.end());
    stack<int> st;
    vi ans;
    for(int i{0}; i < n; ++i){
        int cnt{0};
        while(!st.empty() && st.top() == vec[i] + 1){
            cnt++;
            st.pop();
        }
        ans.push_back(cnt);
        st.push(vec[i]);
    }
    bool flag = true;
    while(!st.empty()){
        flag &= (st.top() == 1);
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if(!flag){
        cout << -1;
        return 0;
    }
    for(auto& i : ans) cout << i << "\n";
}
	

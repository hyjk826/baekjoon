// 2022-08-19
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
    int n;
    cin >> n;
    set<int> st;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        st.insert(a);
    }
    int mx{0};
    for(auto& i : st){
        int cnt{1};
        for(int j{1}; j < 5; ++j){
            if(st.count(i + j)) cnt++;
        }
        mx = max(mx, cnt);
    }
    cout << 5 - mx;
}


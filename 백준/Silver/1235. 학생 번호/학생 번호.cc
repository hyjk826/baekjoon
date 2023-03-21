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
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        reverse(vec[i].begin(), vec[i].end());
    }
    for(int i{0}; i < (int)vec[0].size(); ++i){
        set<string> st;
        for(int j{0}; j < n; ++j){
            st.insert(vec[j].substr(0, i + 1));
        }
        if(st.size() == n){
            cout << i + 1; return 0;
        }
    }

}

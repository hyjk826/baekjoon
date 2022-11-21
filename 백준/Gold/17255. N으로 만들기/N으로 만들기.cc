// 2022-11-21
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

set<string> st;
string str;

void dfs(int L, int l, int r, string s){
    if(L == (int)str.size() - 1){
        st.insert(s);
    }
    else{
        if(l > 0){
            string t;
            t += str[l - 1];
            t += s;
            dfs(L + 1, l - 1, r, s + t);
        }
        if(r < (int)str.size() - 1){
            string t = s;
            t += str[r + 1];
            dfs(L + 1, l, r + 1, s + t);
        }
    }
}

int main() {
	fastio;	
    cin >> str;
    for(int i{0}; i < (int)str.size(); ++i){
        string t;
        t += str[i];
        dfs(0, i, i, t);
    }
    cout << st.size();
}
	


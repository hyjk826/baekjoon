// 2022-09-08
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
    int n, m;
    cin >> n >> m;
    unordered_set<string> st;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        st.insert(str);
    }
    string s;
    getline(cin, s);
    for(int i{0}; i < m; ++i){
        getline(cin, s);
        s += ',';
        string t;
        vector<string> vec;
        for(int j{0}; j < (int)s.size(); ++j){
            if(s[j] == ','){
                if(st.count(t)){
                    st.erase(t);
                }
                t.clear();
            }
            else t += s[j];
        }
        cout << st.size() << "\n";
    }
}
	


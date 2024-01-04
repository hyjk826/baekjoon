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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n; char c;
    cin >> n >> c;
    set<string> st;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        st.insert(str);
    }
    if(c == 'Y'){
        cout << (int)st.size();
    }
    else if(c == 'F'){
        cout << (int)st.size() / 2;
    }
    else{
        cout << (int)st.size() / 3;
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}

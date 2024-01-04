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
	int q;
    cin >> q;
    stack<int> st;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(op == 2){
            if(st.empty()) cout << -1 << "\n";
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(op == 3){
            cout << st.size() << "\n";
        }
        else if(op == 4){
            if(st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else{
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
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

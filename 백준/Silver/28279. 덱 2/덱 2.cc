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

void solve(){
    int q;
    cin >> q;
    deque<int> dQ;
    while(q--){
        int op, x;
        cin >> op;
        if(op <= 2) cin >> x;
        if(op == 1) dQ.push_front(x);
        else if(op == 2) dQ.push_back(x);
        else if(op == 3){
            if(!dQ.empty()){
                cout << dQ.front() << "\n";
                dQ.pop_front();                
            }
            else cout << -1 << "\n";
        }
        else if(op == 4){
            if(!dQ.empty()){
                cout << dQ.back() << "\n";
                dQ.pop_back();                
            }
            else cout << -1 << "\n";
        }
        else if(op == 5){
            cout << dQ.size() << "\n";
        }
        else if(op == 6){
            if(dQ.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(op == 7){
            if(!dQ.empty()) cout << dQ.front() << "\n";
            else cout << -1 << "\n";
        }
        else{
            if(!dQ.empty()) cout << dQ.back() << "\n";
            else cout << -1 << "\n";
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

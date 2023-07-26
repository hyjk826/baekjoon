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
	int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) cout << 1 << "\n";
    else if(n == 1 || m == 1) cout << 2 << "\n";
    else cout << 4 << "\n";
    if(m == 1){
        for(int i{0}; i < n; ++i){
            if(i & 1) cout << 2 << "\n";
            else cout << 1 << "\n";
        }
        return;
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(i & 1){
                if(j & 1) cout << 4 << " ";
                else cout << 3 << " ";
            }
            else{
                if(j & 1) cout << 2 << " ";
                else cout << 1 << " ";
            }            
        }
        cout << "\n";
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


// 1 2 1 2 1 2
// 3 4 3 4 3 4
// 1 2 1 2 1 2
// 3 4 3 4 3 4 
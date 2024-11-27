#include <bits/stdc++.h>
#define MAX 2147000000
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define ll long long 
#define pi pair<int, int>
#define vp vector<pi> 
using namespace std;


void solve(){
	int n;
    cin >> n;
    for(int i{1}; i <= 9; ++i){
        for(int j{1}; j <= 9; ++j){
            if(i == n || j == n || i * j == n){
                cout << 1; return;
            }
        }
    }
    cout << 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
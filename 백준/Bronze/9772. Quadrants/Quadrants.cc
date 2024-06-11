#include <bits/stdc++.h>
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
	double x, y;
    while(cin >> x >> y){        
        if(x == 0 || y == 0) cout << "AXIS\n";
        else{
            if(x > 0){
                if(y > 0) cout << "Q1\n";
                else cout << "Q4\n";
            }
            else{
                if(y > 0) cout << "Q2\n";
                else cout << "Q3\n";
            }
        }
        if(x == 0 && y == 0) break; 
    }
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
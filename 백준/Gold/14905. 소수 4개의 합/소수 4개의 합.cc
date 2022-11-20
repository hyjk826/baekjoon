// 2022-11-20
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

bool checkPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}


int main() {
	fastio;	
    int n;
    while(cin >> n){
        if(n < 8){
            cout << "Impossible.\n";
            continue;
        }
        if(n & 1){
            cout << 2 << " " << 3 << " ";
            n -= 5;
        }
        else {
            cout << 2 << " " << 2 << " ";
            n -= 4;
        }        
        if(checkPrime(n - 2)){
            cout << 2 << " " << n - 2 << "\n";
        }
        else{
            for(int i{3};; i += 2){
                if(checkPrime(i) && checkPrime(n - i)){
                    cout << i << " " << n - i << "\n";
                    break;
                }
            }
        }
    }
}
	


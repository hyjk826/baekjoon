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

bool isPrime(int n){
    if(n == 1) return false;
    for(ll i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    if(k == 1){
        if(isPrime(n)) cout << n;
        else cout << -1;
    }
    else if(k == 2){
        if(n & 1){
            n -= 2;
            if(n <= 1) cout << -1;
            else{
                if(isPrime(n)) cout << 2 << " " << n;
                else cout << -1;
            }
        }
        else{
            if(n == 4) cout << 2 << " " << 2;
            else{
                for(int i{3}; i + i <= n; i += 2){
                    if(isPrime(i) && isPrime(n - i)){
                        cout << i << " " << n - i;
                        return 0;
                    }
                }
                cout << -1;
            }
        }
    }
    else{
        n -= (k - 3) * 2;
        vi ans;
        for(int i{0}; i < k - 3; ++i){
            ans.push_back(2);
        }
        if(n <= 2) {
            cout << -1; return 0;
        }
        if(n & 1) {
            ans.push_back(3);
            n -= 3;
        }
        else {
            ans.push_back(2);
            n -= 2;
        }
        if(n < 4) cout << -1;
        else{
            if(n == 4) {
                ans.push_back(2);
                ans.push_back(2);
            }
            else{
                for(int i{3}; i + i <= n; i += 2){
                    if(isPrime(i) && isPrime(n - i)){
                        ans.push_back(i);
                        ans.push_back(n - i);
                        break;
                    }
                }
            }
            for(auto& i : ans) cout << i << " ";
        }        
    }
}

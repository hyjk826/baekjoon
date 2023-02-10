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

int f(int n){
    int ret{0};
    while(n){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n & 1){
            int a = n / 2;
            int b = n / 2 + 1;
            if(abs((f(a)) - f(b)) <= 1) cout << a << " " << b << "\n";
            else{
                int dif = abs(f(a) - f(b));
                int cnt{1};
                while(1){            
                    a -= cnt * (min(9, dif / 2));
                    b += cnt * (min(9, dif / 2));
                    cnt *= 10;
                    dif = abs(f(a) - f(b));
                    if(dif <= 1) break;
                }                
                cout << a << " " << b << "\n";
            }
        }
        else{
            cout << n / 2 << " " << n / 2 << "\n";
        }
    }
}

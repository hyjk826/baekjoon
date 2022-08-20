// 2022-08-19
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

bool f(ll n){
    ll x = (ll)sqrt(n);
    return x * x == n;
}

int main(){
    fastio;
	ll n;
    cin >> n;
    if(n == 1000000000000){
        cout << 1 << "\n";
        cout << "+ " << 1000000;
        return 0;
    }
    if(n == 0){
        cout << 3 << "\n";
        cout << "- 3\n";
        cout << "- 4\n";
        cout << "+ 5\n";
        return 0;
    }
    bool flag = true;
    if(n < 0){
        flag = false;
        n *= -1;
    }
    if(f(n)){
        cout << 1 << "\n";
        if(flag) cout << "+ ";
        else cout << "- ";
        cout << (ll)sqrt(n);
    }
    else{
        if(n & 1){
            cout << 2 << "\n";
            ll x = (n - 1) / 2;
            if(flag){
                cout << "- " << x << "\n";
                cout << "+ " << x + 1 << "\n";
            }
            else{
                cout << "+ " << x << "\n";
                cout << "- " << x + 1 << "\n";
            }
        }
        else{
            if(n % 4 == 0){
                ll x = (n - 4) / 4;
                cout << "2\n";
                if(flag){
                    cout << "- " << x << "\n";
                    cout << "+ " << x + 2 << "\n";
                }
                else{
                    cout << "+ " << x << "\n";
                    cout << "- " << x + 2 << "\n";
                }
            }
            else{
                for(ll i{1}; i <= (ll)sqrt(n); ++i){
                    if(i * i != n - i * i && f(n - i * i)){
                        cout << "2\n";
                        if(flag){                            
                            cout << "+ " << (ll)sqrt(n - i * i) << "\n";
                            cout << "+ " << i << "\n";
                            return 0;
                        }
                        else{
                            cout << "- " << (ll)sqrt(n - i * i) << "\n";
                            cout << "- " << i << "\n";
                            return 0;
                        }
                    }
                }
                for(ll i{1}; i * i <= n; ++i){
                    if(n % i == 0){
                        ll a = n / i;
                        ll b = i;                        
                        if((a + b) & 1) continue;
                        if((a - b) & 1) continue;
                        ll x = (a + b) / 2;
                        ll y = (a - b) / 2;
                        if(x != y && x > 0 && y > 0){
                            if(flag){
                                cout << 2 << "\n";
                                cout << "+ " << x << "\n";
                                cout << "- " << y << "\n";
                                return 0;
                            }
                            else{
                                cout << 2 << "\n";
                                cout << "- " << x << "\n";
                                cout << "+ " << y << "\n";
                                return 0;
                            }
                        }
                    }
                }
                cout << 3 << "\n";
                if(flag){
                    for(ll i{1};; ++i){
                        ll k = n + i * i;
                        ll x = (k - 1) / 2;
                        if(x > 0 && x != i && x + 1 != i){
                            cout << "- " << i << "\n";
                            cout << "- " << x << "\n";
                            cout << "+ " << x + 1 << "\n";
                            return 0;
                        }
                    }
                }
                else{
                    for(ll i{1};; i += 2){
                        ll k = n + i * i;
                        ll x = (k - 1) / 2;
                        if(x > 0 && x != i && x + 1 != i){
                            cout << "+ " << i << "\n";
                            cout << "+ " << x << "\n";
                            cout << "- " << x + 1 << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
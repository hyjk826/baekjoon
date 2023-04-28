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

int main(){
	fastio;
    int q;
    cin >> q;
    ll a{0}, b{0};
    while(q--){
        ll op, x;
        cin >> op;
        if(op == 1){
            cin >> x;
            a += x;
            b ^= x;
        }
        else if(op == 2){
            cin >> x;
            a -= x;
            b ^= x;
        }
        else if(op == 3){
            cout << a << "\n";
        }
        else cout << b << "\n";
    }
}

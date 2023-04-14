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
    ll n;
    cin >> n;
    ll l{1}, r{n};
    ll a{(n + 1) / 2}, b{(n + 1 ) / 2};
    ll m{(n + 1) / 2};
    cout << "? " << (n + 1) / 2 << endl;
    string k;
    cin >> k;
    while(l <= m){
        ll mid{(l + m) >> 1};
        cout << "? " << mid << endl;
        string str;
        cin >> str;
        if(str == k){
            a = mid;
            m = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    m = (n + 1) / 2;
    while(m <= r){
        ll mid{(r + m) >> 1};
        cout << "? " << mid << endl;
        string str;
        cin >> str;
        if(str == k){
            b = mid;
            m = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << "! " << a << " " << b << endl;
}

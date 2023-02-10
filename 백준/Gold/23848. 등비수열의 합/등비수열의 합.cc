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
    map<ll, pl> mp;
    for(__int128 r{2};;++r){
        if((r * r * r - 1) / (r - 1) > n) break;
        __int128 x = r;
        __int128 k{3};
        __int128 a = x * x * x;
        while(1){            
            __int128 s = (a - 1) / (r - 1);
            if(s > n) break;
            mp[s] = {x, k};
            a *= x;
            k++;
        }
    }
    vl div;
    for(ll i{1}; i * i <= n; ++i){
        if(n % i == 0){
            if(i * i == n) div.push_back(i);
            else{
                div.push_back(i);
                div.push_back(n / i);
            }
        }
    }
    for(auto& i : div){
        ll a = i;
        if(mp.count(n / i)){
            ll r = mp[n / i].first;
            ll k = mp[n / i].second;
            cout << k << "\n";
            for(int i{0}; i < k; ++i){
                cout << a << " ";
                a *= r;
            }
            return 0;
        }
    }
    cout << -1;
}

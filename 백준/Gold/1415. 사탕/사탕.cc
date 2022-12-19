// 2022-12-20
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

vi prime(500001);
vl ch(500001);

int main(){
	fastio;
    prime[1] = 1;
    for(ll i{2}; i <= 500000; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= 500000; j += i){
            prime[j] = 1;
        }
    }
	int n;
    cin >> n;
    map<int, int> mp;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        mp[a]++;
    }
    ch[0] = 1;
    for(auto& i : mp){
        if(i.first == 0){
            ch[0] += i.second;
            continue;
        }
        for(int j{500000 - i.first}; j >= 0; --j){
            if(ch[j] == 0) continue;
            for(int k{1}; k <= i.second && j + k * i.first <= 500000; k++){
                ch[j + k * i.first] += ch[j];
            }
        }
    }
    ll ans{0};
    for(int i{2}; i <= 500000; ++i){
        if(prime[i] == 0) ans += ch[i];
    }
    cout << ans;
}
	

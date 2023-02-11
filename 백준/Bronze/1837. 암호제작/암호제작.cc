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
    string str;
    int k;
    cin >> str >> k;
    vi prime(k);
    for(ll i{2}; i < k; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j < k; j += i){
            prime[j] = 1;
        }
    }
    for(int i{2}; i < k; ++i){
        if(prime[i]) continue;
        int sum{0};
        for(int j{0}; j < (int)str.size(); ++j){
            sum = (sum * 10 + str[j] - '0') % i;
        }
        if(sum == 0){
            cout << "BAD " << i; return 0;
        }
    }
    cout << "GOOD";
}

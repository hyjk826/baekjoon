// 2022-09-11
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

ll pow(ll a, ll b, ll c){
    if(b == 1) return a % c;
    ll k = pow(a, b / 2, c) % c;
    k *= k;
    k %= c;
    if(b & 1){    
        k *= a;
        k %= c;
    }
    return k % c;
}

int main(){
    fastio;
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}
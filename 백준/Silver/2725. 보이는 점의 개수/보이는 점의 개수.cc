// 2022-12-18
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(){
	fastio;
    vi ch(1001);
    for(int i{1}; i <= 1000; ++i){
        for(int j{1}; j <= 1000; ++j){
            if(gcd(i, j) == 1) ch[max(i, j)]++;
        }
    }
    ch[0] = 2;
    for(int i{1}; i <= 1000; ++i){
        ch[i] += ch[i - 1];
    }
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ch[n] << "\n";
    }
}
	

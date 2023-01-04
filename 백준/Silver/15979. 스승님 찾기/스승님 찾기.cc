// 2023-01-04
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
};

int main(){
	fastio;
    int a, b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    if(a == 0 && b == 0) cout << 0;
    else if(a == 0 || b == 0){
        if(a + b == 1) cout << 1;
        else cout << 2;
    }
    else{
        int g = gcd(a, b);
        if(g == 1) cout << 1;
        else cout << 2;
    }
}

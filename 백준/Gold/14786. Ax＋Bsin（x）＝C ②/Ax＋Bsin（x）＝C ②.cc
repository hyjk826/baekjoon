// 2023-01-16
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
    cout << fixed << setprecision(20);
    double a, b, c;
    cin >> a >> b >> c;
    double lo{-1e7}, hi{1e7};
    for(int i{0}; i < 1000000; ++i){
        double m = (lo + hi) / 2;
        double k = a * m + b * sin(m);
        if(k > c){
            hi = m;
        }
        else lo = m;
    }
    cout << lo;
}

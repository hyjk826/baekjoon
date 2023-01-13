// 2023-01-13
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

bool check_prime(int n){
    if(n == 0 || n == 1) return false;
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }   
    return true;
}

vector<vl> com(19, vl(19, -1));

ll f(int a, int b){
    if(com[a][b] != -1) return com[a][b];
    if(a == b || b == 0) return com[a][b] = 1;
    return com[a][b] = f(a - 1, b - 1) + f(a - 1, b);
}



int main(){
	fastio;
    cout << fixed << setprecision(20);
    double a, b;
    cin >> a >> b;
    a /= 100;
    b /= 100;
    double xx{0.0}, yy{0.0};
    for(int i{0}; i <= 18; ++i){
        if(check_prime(i)) continue;
        double x{1.0};
        double y{1.0};
        for(int q{0}; q < i; ++q){
            x *= a;
        }
        for(int q{0}; q < 18 - i; ++q){
            x *= (1.0 - a);
        }
        for(int q{0}; q < i; ++q){
            y *= b;
        }
        for(int q{0}; q < 18 - i; ++q){
            y *= (1.0 - b);
        }
        xx += x * f(18, i);
        yy += y * f(18, i);
    }
    cout << 1.0 - xx * yy;
}

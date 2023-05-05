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

int dist(int x1, int y1, int x, int y){
    x -= x1;
    y -= y1;
    return x * x + y * y;
}


int main(){
	fastio;
    int x1, y1, x2, y2, dx, dy;
    cin >> x1 >> y1 >> x2 >> y2 >> dx >> dy;
    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;
    int pre = dist(x1, y1, x2, y2);
    for(int i{0};;++i){
        x2 += dx;
        y2 += dy;
        int d = dist(x1, y1, x2, y2);
        if(pre < d){
            cout << x2 - dx << " " << y2 - dy; return 0;
        }
        pre = d;
    }
}

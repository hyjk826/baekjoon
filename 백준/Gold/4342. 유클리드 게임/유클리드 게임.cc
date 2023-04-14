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
    function<int(int,int)> f = [&](int a, int b){
        if(a > b) swap(a, b);
        if(a == 0) return 0;
        if(1LL * a * 2 <= b) return 1;
        if(f(a, b - a) == 0) return 1;
        else return 0;
    };
    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        if(f(a, b)) cout << "A wins\n";
        else cout << "B wins\n";
    }
}

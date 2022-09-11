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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(abs(c - d) % gcd(a, b) == 0){
            for(int i{0};;++i){
                int k = i * a + c;
                if((k - d) % b == 0){
                    cout << k << "\n";
                    break;
                }
            }
        }
        else cout << -1 << "\n";
    }
}
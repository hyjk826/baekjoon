// 2023-01-15
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
	int t;
    t=  1;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << 0;
            return 0;
        }
        double d = sqrt(b - a);
        int r = round(d);
        if(d <= r) cout << r * 2 - 1 << "\n";
        else cout << r * 2 << "\n";
    }
}

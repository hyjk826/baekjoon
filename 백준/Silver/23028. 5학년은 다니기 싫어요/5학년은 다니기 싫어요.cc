// 2022-12-21
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
	int n, a, b;
    cin >> n >> a >> b;
    int x, y;
    x = y = 0;
    for(int i{0}; i < 10; ++i){
        int aa, bb;
        cin >> aa >> bb;
        int k = min(6, aa);
        a += k * 3;
        b += k * 3;
        b += min(bb, 6 - k) * 3;
        n++;
        if(a >= 66 && b >= 130) break;
    }
    if(n <= 8) cout << "Nice";
    else cout << "Nae ga wae";
}
	

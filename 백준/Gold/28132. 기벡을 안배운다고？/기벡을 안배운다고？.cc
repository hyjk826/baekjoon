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
    int n;
    cin >> n;
    ll ans{0};
    vp A;
    for(int i{0}; i < n; ++i){
        int x, y;
        cin >> x >> y;
        A.push_back({x, y});
    }
    int a{0}, b{0};
    map<pi, int> mp;
    for(int i{0}; i < n; ++i){
        int x = A[i].first;
        int y = A[i].second;
        if(x == 0 && y == 0){
            b++;
            ans += i;
            continue;
        }
        if(x == 0){
            ans += a;
            mp[{0, 0}]++;
        }
        else{
            if(y == 0){
                if(mp.count({0, 0})) ans += mp[{0, 0}];
                a++;
            }
            else{
                int g = gcd(x, y);
                x /= g; y /= g;
                bool neg = false;
                if(1LL * x * y < 0) neg = true;
                if(neg) ans += mp[{-abs(y), abs(x)}];
                else ans += mp[{abs(y), abs(x)}];
                if(neg) mp[{abs(x), abs(y)}]++;
                else mp[{-abs(x), abs(y)}]++;
            }
        }
        ans += b;
    }
    cout << ans;
}

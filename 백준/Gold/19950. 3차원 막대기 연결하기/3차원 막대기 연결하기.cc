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
    int x0, y0, z0, x1, y1, z1;
    cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
    int x = x0 - x1;
    int y = y0 - y1;
    int z = z0 - z1;
    int dist = x * x + y * y + z * z;
    int n;
    cin >> n;
    vi vec(n);
    int sum{0};
    int mx{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
        mx = max(mx, vec[i]);
    }
    if(sum * sum < dist) cout << "NO\n";
    else{
        int k = max(0, mx - (sum - mx));
        if(k * k > dist) cout << "NO\n";
        else cout << "YES\n";
    }
}

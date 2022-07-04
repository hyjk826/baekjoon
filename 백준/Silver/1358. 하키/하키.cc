// 2022-07-04
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

double dis(pi a, pi b){
    int aa = a.first - b.first;
    int bb = a.second - b.second;
    return sqrt(aa * aa + bb * bb);
}

int main(){
    fastio;
	int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;
    int ans{0};
    while(p--){
        int a, b;
        cin >> a >> b;
        if(x <= a && a <= x + w){
            if(y <= b && b <= y + h) ans++;
        }
        else{
            if(dis({a, b}, {x, y + 1.0 * h / 2}) <= 1.0 * h / 2 || dis({a, b}, {x + w, y + 1.0 * h / 2}) <= 1.0 * h / 2) ans++;
        }
    }
    cout << ans;
}
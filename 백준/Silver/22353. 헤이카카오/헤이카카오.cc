// 2022-06-20
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

int main(){
    fastio;
	int a, d, k;
    cin >> a >> d >> k;
    double ans{0};
    cout << fixed << setprecision(10);
    double c;
    double b = 1.0 * d / 100;
    double u = 1.0 * k / 100 + 1.0;
    vector<double> vec;
    double sum{0};
    while(1){
        vec.push_back(b);
        if(b >= 1.0) break;
        b *= u;
        if(b >= 1.0) b = 1.0;
    }
    for(int i{0}; i < (int)vec.size(); ++i){
        ans += a * 1.0 * (i + 1) * (1 - sum) * vec[i];
        sum += (1 - sum) * vec[i];
    }
    cout << ans;
}
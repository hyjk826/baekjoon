// 2022-09-09
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

int main(){
    fastio;
	int n;
    cin >> n;
    vi vec(n);
    int mx{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        mx = max(mx, vec[i]);
    }
    double sum{0};
    for(int i{0}; i < n; ++i){
        sum += 1.0 * vec[i] / mx * 100;
    }
    cout << fixed << setprecision(10);
    cout << sum / n;    
}
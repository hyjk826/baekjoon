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
    vector<double> vec(10);
    for(int i{0}; i < 10; ++i){
        cin >> vec[i];
    }
    double ans{1};
    sort(vec.rbegin(), vec.rend());
    for(int i{0}; i < 9; ++i){
        ans *= vec[i] / (i + 1);
    }
    ans *= 1e9;
    cout << fixed << setprecision(20);
    cout << ans;
}

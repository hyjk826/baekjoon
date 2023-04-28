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
#define double long double
using namespace std;

int main(){
	int n, k;
    cin >> n >> k;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vl preSum = vec;
    for(int i{1}; i <= n; ++i){
        preSum[i] += preSum[i - 1];
    }
    vl sqareSum = vec;
    for(int i{1}; i <= n; ++i){
        sqareSum[i] = vec[i] * vec[i];
        sqareSum[i] += sqareSum[i - 1];
    }
    double ans{1e16};
    for(int i{0}; i + k <= n; ++i){
        for(int j{i + k}; j <= n; ++j){
            double mean = 1.0 * (preSum[j] - preSum[i]) / (j - i);
            double sum = 1.0 * sqareSum[j] - sqareSum[i];
            sum -= 2 * mean * (1.0 * preSum[j] - preSum[i]);
            sum += (j - i) * mean * mean;
            sum /= (j - i);
            ans = min(ans, sqrt(sum));
        }
    }
    cout << fixed << setprecision(20);
    cout << ans;
}

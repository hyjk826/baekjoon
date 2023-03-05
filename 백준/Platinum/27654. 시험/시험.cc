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
    int n, k;
    cin >> n >> k;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    double l{0}, r{1e10};
    double ans{0};
    for(int i{0}; i < 100; ++i){
        double mid = (l + r) / 2;
        priority_queue<double> pQ;
        for(int j{0}; j < n; ++j){
            pQ.push(-vec[j].second * mid + vec[j].first);
        }
        double sum{0};
        for(int j{0}; j < k; ++j){
            sum += pQ.top();
            pQ.pop();
        }
        if(sum >= 0){
            ans = mid;
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(20);
    cout << ans;
}

// 2022-09-14
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pl> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    ll sum{0};
    for(int i{0}; i < n - 1; ++i){
        sum += vec[i].first * vec[i + 1].second;
    }
    sum += vec[n - 1].first * vec[0].second;
    for(int i{0}; i < n - 1; ++i){
        sum -= vec[i].second * vec[i + 1].first;
    }
    sum -= vec[n - 1].second * vec[0].first;
    sum = abs(sum);
    printf("%.1f", sum / 2.0);
}
	


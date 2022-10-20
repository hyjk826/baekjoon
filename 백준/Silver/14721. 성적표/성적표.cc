// 2022-10-20
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
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int mn{MAX};
    int a{-1}, b{-1};
    for(int i{1}; i <= 100; ++i){
        for(int j{1}; j <= 100; ++j){
            ll sum{0};
            for(int k{0}; k < n; ++k){
                ll s = vec[k].second - (1LL * i * vec[k].first + j);
                sum += s * s;
            }
            if(mn > sum){
                mn = sum;
                a = i;
                b = j;
            }
        }
    }
    cout << a << " " << b;
}
	


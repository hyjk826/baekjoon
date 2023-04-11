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
    int n;
    cin >> n;
    vp vec(n);
    ll sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        sum += vec[i].second;
    }
    sort(vec.begin(), vec.end());
    ll k{0};
    for(int i{0}; i < n; ++i){
        k += vec[i].second;
        if(k >= (sum + 1) / 2){
            cout << vec[i].first; return 0;
        }
    }
}

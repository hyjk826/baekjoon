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

ll dist(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	fastio;
    int n;
    cin >> n;
    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    ll mn{LLONG_MAX};
    int idx{-1};
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vpl A(m);
        for(int j{0}; j < m; ++j){
            cin >> A[j].first >> A[j].second;
        }
        ll sum{0};
        sum += dist(sx, sy, A[0].first, A[0].second);
        for(int j{0}; j < m - 1; ++j){
            sum += dist(A[j].first, A[j].second, A[j + 1].first, A[j + 1].second);
        }
        sum += dist(A.back().first, A.back().second, ex, ey);
        if(sum < mn){
            mn = sum;
            idx = i + 1;
        }
    }
    cout << idx;
}

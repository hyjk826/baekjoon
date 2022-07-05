// 2022-07-05
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
	ll n, c;
    cin >> n >> c;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int h{n / 2};
    vl A, B;
    for(int i{0}; i < (1 << h); ++i){
        ll sum{0};
        for(int j{0}; j < h; ++j){
            if((i >> j) & 1) sum += vec[j];
        }
        A.push_back(sum);
    }
    for(int i{0}; i < (1 << (n - h)); ++i){
        ll sum{0};
        for(int j{0}; j < n - h; ++j){
            if((i >> j) & 1) sum += vec[j + h];
        }
        B.push_back(sum);
    }
    sort(B.begin(), B.end());
    ll ans{0};
    for(int i{0}; i < (int)A.size(); ++i){
        ans += upper_bound(B.begin(), B.end(), c - A[i]) - B.begin();
    }
    cout << ans;
}
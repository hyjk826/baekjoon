// 2022-06-22
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
	int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    map<int, int> A;
    for(int i{0}; i < (1 << (n / 2)); ++i){
        int sum{0};
        for(int j{0}; j < n / 2; ++j){
            if((i >> j) & 1){
                sum += vec[j];
            }
        }
        A[sum]++;
    }
    ll ans{0};
    for(int i{0}; i < (1 << (n - n / 2)); ++i){
        int sum{0};
        for(int j{0}; j < n - n / 2; ++j){
            if((i >> j) & 1){
                sum += vec[n / 2 + j];
            }
        }
        ans += A[k - sum];
    }
    if(k == 0) ans--;
    cout << ans;
}
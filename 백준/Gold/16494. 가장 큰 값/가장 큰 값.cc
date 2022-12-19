// 2022-12-18
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
	int n, m;
    cin >> n >> m;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int ans{-MAX};
    for(int i{0}; i < (1 << n); ++i){
        if(__builtin_popcount(i) < m) continue;
        vi A;
        for(int j{0}; j < n; ++j){
            A.push_back((i >> j) & 1);
        }
        int sum{0};
        vi B;
        for(int j{0}; j < n; ++j){
            if(A[j]){
                if(j == 0) B.push_back(vec[j]);
                else{
                    if(A[j - 1]) B.back() += vec[j];
                    else B.push_back(vec[j]);
                }
            }
        }
        if(B.size() <= m){
            ans = max(ans, accumulate(B.begin(), B.end(), 0));
        }
    }
    cout << ans;
}
	

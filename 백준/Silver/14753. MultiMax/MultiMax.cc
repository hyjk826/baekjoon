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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vi A;
    if(n > 6){
        for(int i{0}; i < 3; ++i) A.push_back(vec[i]);
        for(int i{n - 3}; i <= n - 1; ++i) A.push_back(vec[i]);
    }
    else{
        A = vec;
    }
    int ans{-MAX};
    for(int i{0}; i < (int)A.size(); ++i){
        for(int j{i + 1}; j < (int)A.size(); ++j){
            ans = max(ans, A[i] * A[j]);
            for(int k{j + 1}; k < (int)A.size(); ++k){
                ans = max(ans, A[i] * A[j] * A[k]);
            }
        }
    }
    cout << ans;
}

// 2022-08-19
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    vi vec(2 * n);
    for(int i{0}; i < 2 * n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int ans{MAX};
    for(int i{0}; i < n; ++i){
        ans = min(ans, vec[i] + vec[2 * n - i - 1]);
    }
    cout << ans;
}
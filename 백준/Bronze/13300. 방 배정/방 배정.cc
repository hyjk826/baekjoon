// 2022-07-23
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    int arr[6][2]{};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        b--;
        arr[b][a]++;
    }
    int ans{0};
    for(int i{0}; i < 6; ++i){
        for(int j{0}; j < 2; ++j){
            ans += (arr[i][j] + k - 1) / k;
        }
    }
    cout << ans;
}


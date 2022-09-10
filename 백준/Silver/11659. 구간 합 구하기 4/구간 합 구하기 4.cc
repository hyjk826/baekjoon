// 2022-09-10
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
    int n, m;
    cin >> n >> m;
    vl preSum(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> preSum[i];
        preSum[i] += preSum[i - 1];
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << preSum[r] - preSum[l - 1] << "\n";
    }
}
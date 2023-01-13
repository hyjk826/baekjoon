// 2023-01-14
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
    vi dp(m + 1, -1);
    dp[0] = 0;
    vp A;
    for(int i{0}; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        int sum{0};
        for(int j{0}; j < 20; ++j){
            if(sum + (1 << j) <= c){
                sum += (1 << j);
                A.push_back({a * (1 << j), b * (1 << j)});
            }
            else break;
        }
        A.push_back({a * (c - sum), b * (c - sum)});
    }
    for(int i{0}; i < (int)A.size(); ++i){
        for(int j{m - A[i].first}; j >= 0; --j){
            if(dp[j] == -1) continue;
            dp[j + A[i].first] = max(dp[j + A[i].first], dp[j] + A[i].second);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

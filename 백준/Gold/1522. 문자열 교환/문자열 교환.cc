// 2022-09-08
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    string str;
    cin >> str;
    int cnt{0};
    for(auto& c : str){
        if(c == 'b') cnt++;
    }
    str += str;
    vi preSum((int)str.size() + 1);
    for(int i{1}; i <= (int)str.size(); ++i){
        if(str[i - 1] == 'b') preSum[i]++;
        preSum[i] += preSum[i - 1];
    }
    int ans{MAX};
    for(int i{0}; i <= (int)str.size() - cnt; ++i){
        int k = preSum[i + cnt] - preSum[i];
        ans = min(ans, cnt - k);
    }
    if(ans == MAX) cout << 0;
    else cout << ans;
}
	


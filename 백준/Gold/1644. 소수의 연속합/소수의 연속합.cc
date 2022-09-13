// 2022-09-14
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

vi prime(4000001);

int main() {
	fastio;
    prime[1] = 1;
    for(int i{2}; i <= 4000000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 4000000; j += i){
                prime[j] = 1;
            }
        }
    }
    vi vec;
    for(int i{1}; i <= 4000000; ++i){
        if(prime[i] == 0){
            vec.push_back(i);
        }
    }
    vl preSum;
    preSum.push_back(0);
    for(auto& i : vec){
        preSum.push_back(preSum.back() + i);
    }
    ll ans{0};
    int n;
    cin >> n;
    for(int i{0}; i < (int)preSum.size(); ++i){
        ll k = preSum[i] + n;
        auto it = lower_bound(preSum.begin(), preSum.end(), k);
        if(it == preSum.end()) break;
        if(*it == k) ans++;
    }
    cout << ans;
}
	


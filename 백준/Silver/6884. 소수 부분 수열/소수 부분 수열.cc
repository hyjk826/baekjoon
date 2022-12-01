// 2022-12-01
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

vector<bool> prime((int)1e8 + 1);


int main() {
	fastio;
	prime[1] = 1;
    for(ll i{2}; i <= (int)1e8; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)1e8; j += i){
            prime[j] = 1;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n + 1);
        vi pre(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
            pre[i] = pre[i - 1] + vec[i];
        }
        bool flag = false;
        for(int i{2}; i <= n; ++i){
            for(int j{0}; j + i <= n; ++j){
                if(prime[pre[j + i] - pre[j]] == 0){
                    flag = true;
                    cout << "Shortest primed subsequence is length " << i << ": ";
                    for(int k{j + 1}; k < j + i + 1; ++k){
                        cout << vec[k] << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout << "This sequence is anti-primed.\n";
    }
}
	
